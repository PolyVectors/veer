#include <iostream>
#include <stdexcept>

#include "lexer.hpp"
#include "parser.hpp"

Node::Node(Node* left, Token op, Node* right) : left(left), op(op), right(right) {}
Node::Node(Token op) : left(nullptr), op(op), right(nullptr) {}

Parser::Parser(std::vector<Token> tokens) : tokens(tokens), pos(0) {}

void Parser::consume() {
	if (this->pos >= this->tokens.size())
		throw std::invalid_argument("Attempted to eat nonexistant token");

	this->pos++;
}

Token Parser::currentToken() {
	return this->tokens[this->pos];
}

// <factor> ::= "Integer" | <"LParen" <expression> "RParen">
Node Parser::factor() {
	Node node = Node(this->currentToken());

	if (this->currentToken().type == TokenType::Integer) {
		this->consume();
		return node;
	} else if (this->currentToken().type == TokenType::LParen) {
		std::cout << this->currentToken().value << "\n";

		this->consume();
		node = this->expression();
		this->consume();
		return node;
	} else {
		throw std::invalid_argument("Unexpected token");
	}

	return node;
}

// <term> ::= <factor> | <factor> <"Multiply" | "Divide"> <factor>
Node Parser::term() {
	return this->factor();
}

// <expression> ::= <term> | <term> <"Plus" | "Minus"> <term>
Node Parser::expression() {
	return this->term();
}

Node Parser::parse() {
	return this->expression();
}
