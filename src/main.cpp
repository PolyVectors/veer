#include <iostream>

#include "lexer.hpp"
#include "parser.hpp"

int main() {
	Lexer lexer("123 + 1");
	Parser parser(lexer.lex());
	parser.parse();

	return 0;
}
