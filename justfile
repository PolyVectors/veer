build:
	g++ -o veer -std=c++20 \
		-Isrc/compiler/frontend \
		src/main.cpp \
		src/compiler/frontend/lexer.cpp \
		src/compiler/frontend/parser.cpp
