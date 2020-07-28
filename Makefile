#
# Definitions
#

# Directories
DirSrc = src
DirOut = out
DirData = data
DirTools = tools

# Tools
Lex = $(DirTools)\\flex.exe
Yacc = $(DirTools)\\bison.exe

# Output
OutputName = explorer.exe

#
# Commands
#

all:
	@make -s build
	@make -s run

clear:
	powershell clear

clean:
	powershell rm $(DirOut) -Force -Recurse

copy:
	powershell cp $(DirSrc) $(DirOut) -Force -Recurse

gen:
	$(Lex) -o $(DirOut)/Lexer.cpp $(DirSrc)/Parsers/Rules/Lexer.l
	$(Yacc) -d -o $(DirOut)/Parser.cpp $(DirSrc)/Parsers/Rules/Parser.y

compile_parser:
	@make -s gen
	g++ -c $(DirOut)/Lexer.cpp -o $(DirOut)/Lexer.o
	g++ -c $(DirOut)/Parser.cpp -o $(DirOut)/Parser.o

compile_client:
	g++ -std=c++17 -o $(DirOut)/$(OutputName) \
			$(DirOut)/Client/Main.cpp \
			\
			$(DirOut)/Parsers/Tree/Expressions/ColumnNode.cpp \
			$(DirOut)/Parsers/Tree/Expressions/ExpressionNode.cpp \
			$(DirOut)/Parsers/Tree/Expressions/OperatorNode.cpp \
			$(DirOut)/Parsers/Tree/Expressions/ValueNode.cpp \
			\
			$(DirOut)/Parsers/Tree/Statements/CreateDirNode.cpp \
			$(DirOut)/Parsers/Tree/Statements/DropDirNode.cpp \
			\
			$(DirOut)/Lexer.o \
			$(DirOut)/Parser.o

compile_all:
	@make -s compile_parser
	@make -s compile_client

build:
	@make -s clear
	@make -s clean
	@make -s copy
	@make -s compile_all

run:
	@make -s clear
	$(DirOut)\\$(OutputName) < $(DirData)/input.txt
