#include "lexer.hpp"

#pragma once

struct Node {
	Node* left;
	Token op;
	Node* right;

	Node(Node* left, Token op, Node* right);
	Node(Token op);
};

class Parser {
private:
	unsigned int pos;
	std::vector<Token> tokens;

	void consume();
	Token currentToken();

	Node factor();
	Node term();
	Node expression();
public:
	Parser(std::vector<Token> tokens);
	Node parse();
};
