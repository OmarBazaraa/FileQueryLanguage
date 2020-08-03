cmake_minimum_required(VERSION 3.8)

#
# Configuration
#

# Define Directories
set(TOOLS_DIR ${CMAKE_SOURCE_DIR}/tools)
set(TOOL_LEX ${TOOLS_DIR}/flex.exe)
set(TOOL_YACC ${TOOLS_DIR}/bison.exe)
set(TOOL_INCLUDE_DIR "${TOOLS_DIR}/include")

#
# Generate Parser & Lexer Commands
#

# 1. Parser
set(FQL_PARSER_GRAMMAR ${CMAKE_CURRENT_SOURCE_DIR}/Parsers/Rules/ParserGrammar.y)
set(FQL_PARSER_FILE ${CMAKE_CURRENT_BINARY_DIR}/Parser.cpp)
set(FQL_PARSER_HEADER_FILE ${CMAKE_CURRENT_BINARY_DIR}/Parser.hpp)

add_custom_command(
    OUTPUT ${FQL_PARSER_FILE} ${FQL_PARSER_HEADER_FILE}
    COMMAND ${TOOL_YACC} -d -o ${FQL_PARSER_FILE} ${FQL_PARSER_GRAMMAR}
    DEPENDS ${FQL_PARSER_GRAMMAR}
    COMMENT "Generating FQL Parser..."
)

# 2. Lexer
set(FQL_LEXER_SPECS ${CMAKE_CURRENT_SOURCE_DIR}/Parsers/Rules/LexerSpecs.l)
set(FQL_LEXER_FILE ${CMAKE_CURRENT_BINARY_DIR}/Lexer.cpp)

add_custom_command(
    OUTPUT ${FQL_LEXER_FILE}
    COMMAND ${TOOL_LEX} -o ${FQL_LEXER_FILE} ${FQL_LEXER_SPECS}
    DEPENDS ${FQL_LEXER_SPECS}
    COMMENT "Generating FQL Lexer..."
)

#
# Build Parser & Lexer
#

# 1. Parser
add_library(FqlParserLib STATIC ${FQL_PARSER_FILE} ${FQL_PARSER_HEADER_FILE})

target_include_directories(FqlParserLib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${TOOL_INCLUDE_DIR})

set_property(TARGET FqlParserLib PROPERTY CXX_STANDARD 11)

# 2. Lexer
add_library(FqlLexerLib STATIC ${FQL_LEXER_FILE} ${FQL_PARSER_HEADER_FILE})

target_include_directories(FqlLexerLib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${TOOL_INCLUDE_DIR})

set_property(TARGET FqlLexerLib PROPERTY CXX_STANDARD 11)

#
# Build FQL
#

# 1. FQL Core
file(GLOB_RECURSE FQL_CORE_SRC_FILES "Common/*.cpp" "Parsers/*.cpp")

add_library(FqlCoreLib STATIC ${FQL_CORE_SRC_FILES})

target_include_directories(FqlCoreLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(FqlCoreLib FqlLexerLib FqlParserLib)

set_property(TARGET FqlCoreLib PROPERTY CXX_STANDARD 17)

# 2. FQL Client

file(GLOB_RECURSE FQL_CLIENT_SRC_FILES "Client/*.cpp")

add_executable(FqlClient ${FQL_CLIENT_SRC_FILES})

target_link_libraries(FqlClient FqlCoreLib)

set_property(TARGET FqlClient PROPERTY CXX_STANDARD 17)
