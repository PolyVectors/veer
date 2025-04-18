#include <memory>
#include <iostream>
#include <stdexcept>

#include "lexer.hpp"
#include "parser.hpp"

Node::Node(Token op) : left(nullptr), op(op), right(nullptr) {}

Node::Node(std::unique_ptr<Node> left, Token op, std::unique_ptr<Node> right)
	: left(std::move(left)), op(op), right(std::move(right)) {}

Parser::Parser(std::vector<Token> tokens) : tokens(tokens), pos(0) {}

void Parser::consume(TokenType type) {
	if (this->pos >= this->tokens.size())
		throw std::invalid_argument("Attempted to eat nonexistent token");
	
	if (this->currentToken().type != type)
		throw std::invalid_argument("Expected different token");

	this->pos++;
}

Token Parser::currentToken() {
	return this->tokens.at(this->pos);
}

// <factor> ::= "Integer" | <"LParen" <expression> "RParen">
std::unique_ptr<Node> Parser::factor() {
	if (this->currentToken().type == TokenType::Integer) {
		auto node = std::make_unique<Node>(this->currentToken());
		this->consume(TokenType::Integer);
		return node;
	}

	this->consume(TokenType::LParen);
	auto node = this->expression();
	this->consume(TokenType::RParen);
	return node;
}

// <term> ::= <factor> | <factor> <"Multiply" | "Divide"> <factor>
std::unique_ptr<Node> Parser::term() {
	auto node = this->factor();

	while (this->pos < this->tokens.size()) {
		if (!(this->currentToken().type == TokenType::Multiply || this->currentToken().type == TokenType::Divide))
			break;

		Token op = this->currentToken();
		this->consume(this->currentToken().type);
		
		node = std::make_unique<Node>(std::move(node), op, std::move(this->factor()));
	}

	return node;
}

// <expression> ::= <term> | <term> <"Plus" | "Minus"> <term>
std::unique_ptr<Node> Parser::expression() {
	auto node = this->term();

	while (this->pos < this->tokens.size()) {
		if (!(this->currentToken().type == TokenType::Plus || this->currentToken().type == TokenType::Minus))
			break;

		Token op = this->currentToken();
		this->consume(this->currentToken().type);
		
		node = std::make_unique<Node>(std::move(node), op, std::move(this->factor()));
	}

	return node;
}

std::unique_ptr<Node> Parser::parse() {
	return this->expression();
}
