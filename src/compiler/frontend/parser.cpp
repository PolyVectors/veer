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
	if (this->pos >= this->tokens.size())
		return node;

	switch (this->currentToken().type) {
		case TokenType::Multiply:
		case TokenType::Divide: {
			Token op = this->currentToken();
			this->consume(op.type);

			auto right = this->factor();
			return std::make_unique<Node>(std::move(node), op, std::move(right));
			break;
		}
		case TokenType::Plus:
		case TokenType::Minus: {
			return node;
			break;
		}
		default:
			throw std::invalid_argument("Expected different token when parsing term");
			break;
	}

	return node;
}

// <expression> ::= <term> | <term> <"Plus" | "Minus"> <term>
std::unique_ptr<Node> Parser::expression() {
	auto node = this->term();
	if (this->pos >= this->tokens.size())
		return node;

	switch (this->currentToken().type) {
		case TokenType::Plus:
		case TokenType::Minus:{
			Token op = this->currentToken();
			this->consume(op.type);
		
			auto right = this->factor();
			return std::make_unique<Node>(std::move(node), op, std::move(right));
			break;
		}
		default:
			throw std::invalid_argument("Expected different token when parsing expression");
			break;
	}

	return node;
}

std::unique_ptr<Node> Parser::parse() {
	return this->expression();
}
