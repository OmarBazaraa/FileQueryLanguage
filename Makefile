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
ClientName = fql-client.exe

#
# Commands
#

all:
	@make -s build
	@make -s run

clear:
	powershell clear

clean:
	powershell mkdir $(DirOut) -Force | powershell Out-Null
	powershell rm $(DirOut) -Force -Recurse

copy:
	powershell cp $(DirSrc) $(DirOut) -Force -Recurse

gen:
	$(Lex) -o $(DirOut)/Parsers/Rules/Lexer.cpp $(DirSrc)/Parsers/Rules/Lexer.l
	$(Yacc) -d -o $(DirOut)/Parsers/Rules/Parser.cpp $(DirSrc)/Parsers/Rules/Parser.y

compile_parser:
	@make -s gen
	g++ -c $(DirOut)/Parsers/Rules/Lexer.cpp -o $(DirOut)/Lexer.o
	g++ -c $(DirOut)/Parsers/Rules/Parser.cpp -o $(DirOut)/Parser.o

compile_client:
	g++ -std=c++17 -o $(DirOut)/$(ClientName) \
			$(DirOut)/Client/Main.cpp \
			\
			$(DirOut)/Parsers/Tree/Clauses/GroupByNode.cpp \
			$(DirOut)/Parsers/Tree/Clauses/HavingNode.cpp \
			$(DirOut)/Parsers/Tree/Clauses/LimitNode.cpp \
			$(DirOut)/Parsers/Tree/Clauses/OrderByNode.cpp \
			$(DirOut)/Parsers/Tree/Clauses/SortRuleNode.cpp \
			$(DirOut)/Parsers/Tree/Clauses/WhereNode.cpp \
			\
			$(DirOut)/Parsers/Tree/Expressions/ColumnNode.cpp \
			$(DirOut)/Parsers/Tree/Expressions/ExpressionNode.cpp \
			$(DirOut)/Parsers/Tree/Expressions/FunctionNode.cpp \
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
	$(DirOut)\\$(ClientName) < $(DirData)/input.txt
