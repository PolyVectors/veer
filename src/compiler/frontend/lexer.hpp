#include <string>
#include <vector>

#pragma once

enum TokenType {
	Integer,
	Plus,
	Minus,
	Multiply,
	Divide,
	LParen,
	RParen,
};

struct Token {
	TokenType type;
	std::string value;

	Token(TokenType type, std::string value);
};

class Lexer {
private:
	unsigned int pos;
	std::string source;
	std::vector<Token> tokens;

	void addInteger();
	void addOperator();
	void addParenthesis();
public:
	Lexer(std::string source);
	std::vector<Token> lex();
};
