#include <vector>
#include <stdexcept>
#include <string>

#include "lexer.hpp"

Token::Token(TokenType type, std::string value) : type(type), value(value) {}
Lexer::Lexer(std::string source) : source(source), pos(0) {}

void Lexer::addInteger() {
	std::string integer;
	bool break_out = false;

	while (this->pos < this->source.length()) {
		if (break_out == true)
			break;		

		switch (this->source.at(this->pos)) {
			case '0' ... '9':
				integer = integer + this->source.at(this->pos);
				this->pos++;
				break;
			default:
				break_out = true;
				break;
		}
	}

	this->tokens.push_back(Token(TokenType::Integer, integer));
}

void Lexer::addOperator() {
	TokenType token_type;

	switch (this->source[this->pos]) {
		case '+':
			token_type = TokenType::Plus;
			break;
		case '-':
			token_type = TokenType::Minus;
			break;
		case '*':
			token_type = TokenType::Multiply;
			break;
		case '/':
			token_type = TokenType::Divide;
			break;
	}

	this->pos++;
	this->tokens.push_back(Token(token_type, ""));
}

void Lexer::addParenthesis() {
	TokenType token_type;
	token_type = this->source.at(this->pos) == '(' ? TokenType::LParen : TokenType::RParen;  

	this->pos++;;
	this->tokens.push_back(Token(token_type, ""));
}

std::vector<Token> Lexer::lex() {
	while (this->pos < this->source.length()) {
		switch (this->source.at(this->pos)) {
			case '0' ... '9':
				this->addInteger();
				break;
			case '+': case '-': case '*': case '/':
				this->addOperator();
				break;
			case '(': case ')':
				this->addParenthesis();
				break;
			case ' ':
				this->pos++;
				break;	
			default:
				throw std::invalid_argument("Unexpected character");
				break;
		}

	}

	return this->tokens;
}
