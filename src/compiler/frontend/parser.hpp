#include <memory>
#include "lexer.hpp"

#pragma once

struct Node {
	std::unique_ptr<Node> left;
	Token op;
	std::unique_ptr<Node> right;

	Node(Token op);
	Node(std::unique_ptr<Node> left, Token op, std::unique_ptr<Node> right);
};

class Parser {
private:
	unsigned int pos;
	std::vector<Token> tokens;

	void consume(TokenType type);
	Token currentToken();

	std::unique_ptr<Node> factor();
	std::unique_ptr<Node> term();
	std::unique_ptr<Node> expression();
public:
	Parser(std::vector<Token> tokens);
	std::unique_ptr<Node> parse();
};
