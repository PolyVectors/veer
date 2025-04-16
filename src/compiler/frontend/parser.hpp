#include "lexer.hpp"

#pragma once

struct Node {
	Node* left;
	Token value;
	Node* right;

	Node(Node* left, Token value, Node* right);
	Node(Token value);
};

class Parser {
private:
	unsigned int pos;
	std::vector<Token> tokens;

	void consume();
	void factor();
	void term();
	void expression();
public:
	Parser(std::vector<Token> tokens);
	Node parse();
};
