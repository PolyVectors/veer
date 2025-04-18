#include <iostream>
#include <memory>

#include "lexer.hpp"
#include "parser.hpp"

int main() {
	Lexer lexer("1 + 2");
	Parser parser(lexer.lex());
	
	std::unique_ptr<Node> node = parser.parse();
	std::cout << node.get()->op.type << "\n";

	return 0;
}
