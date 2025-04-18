#include <iostream>
#include <memory>

#include "lexer.hpp"
#include "parser.hpp"

int main() {
	Lexer lexer("1 + 2 + 3 + 4");
	Parser parser(lexer.lex());
	
	std::unique_ptr<Node> node = parser.parse();
	std::cout << node.get()->left.get()->op.value << "\n";

	return 0;
}
