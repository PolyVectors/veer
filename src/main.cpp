#include <iostream>

#include "lexer.hpp"
#include "parser.hpp"

int main() {
	Lexer lexer("(1)");
	Parser parser(lexer.lex());
	
	Node node = parser.parse();
	std::cout << node.op.value << "\n";

	return 0;
}
