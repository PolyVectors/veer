# veer
simple, zero dependency systems programming language designed for creating tiny ELF executable binaries

## current scope
write a preprocessor (strips comments, expands and strips directives), lexer (creates an array of type Instruction [struct of mnemonic and operand(s)]) and machine code generator (determines opcode and REX prefix from mnemonic) for x86-64 veer assembly

## references

### books
[Writing a C Compiler: Build a Real Programming Language from Scratch by Nora Sandler](https://nostarch.com/writing-c-compiler)
\
[Crafting Interpreters by Robert Nystrom](https://craftinginterpreters.com/)

### blog posts
[Building Recursive Descent Parsers: The Definitive Guide by Supriyo Biswas](https://www.booleanworld.com/building-recursive-descent-parsers-definitive-guide/)
\
[Let’s Build A Simple Interpreter. Part 7: Abstract Syntax Trees by Ruslan Spivak](https://ruslanspivak.com/lsbasi-part7/)

### articles
[Recursive descent parser in C - Wikipedia](https://en.wikipedia.org/wiki/Recursive_descent_parser#C_implementation)
\
[Backus-Naur form - Wikipedia](https://en.wikipedia.org/wiki/Backus%E2%80%93Naur_form)

### manuals
[AMD64 Architecture Programmer’s Manual Volume 3: General-Purpose and System Instructions](https://community.amd.com/sdtpp67534/attachments/sdtpp67534/processors-discussions/29160/1/AMD64-3.pdf)

### inspirational projects
[flat assembler](https://github.com/tgrysztar/fasm)
\
[dmd](https://github.com/dlang/dmd/)