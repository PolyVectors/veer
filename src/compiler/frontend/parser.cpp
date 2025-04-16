#include "parser.hpp"

Node::Node(Node* left, Token value, Node* right) : left(left), value(value), right(right) {}
Node::Node(Token value) : left(nullptr), value(value), right(nullptr) {}

Parser::Parser(std::vector<Token> tokens) : tokens(tokens), pos(0) {}

void Parser::consume() {}

// <factor> ::= "Integer" | <"LParen" <expression> "RParen">
void Parser::factor() {}

// <term> ::= <factor> | <factor> <"Multiply" | "Divide"> <factor>
void Parser::term() {}

// <term> ::= <factor> | <factor> <"Multiply" | "Divide"> <factor>
void Parser::expression() {}

Node Parser::parse() {
	return Node(this->tokens.front());
}
