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
add_library(FQL_PARSER_LIB STATIC ${FQL_PARSER_FILE} ${FQL_PARSER_HEADER_FILE})

target_include_directories(FQL_PARSER_LIB PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${TOOL_INCLUDE_DIR})

set_property(TARGET FQL_PARSER_LIB PROPERTY CXX_STANDARD 11)

# 2. Lexer
add_library(FQL_LEXER_LIB STATIC ${FQL_LEXER_FILE} ${FQL_PARSER_HEADER_FILE})

target_include_directories(FQL_LEXER_LIB PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${TOOL_INCLUDE_DIR})

set_property(TARGET FQL_LEXER_LIB PROPERTY CXX_STANDARD 11)

#
# Build FQL
#

# 1. FQL Core
file(GLOB_RECURSE FQL_CORE_SRC_FILES "Common/*.cpp" "Parsers/*.cpp")

add_library(FQL_CORE_LIB STATIC ${FQL_CORE_SRC_FILES})

target_include_directories(FQL_CORE_LIB PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(FQL_CORE_LIB FQL_LEXER_LIB FQL_PARSER_LIB)

set_property(TARGET FQL_CORE_LIB PROPERTY CXX_STANDARD 17)

# 2. FQL Client

file(GLOB_RECURSE FQL_CLIENT_SRC_FILES "Client/*.cpp")

add_executable(FQL_CLIENT ${FQL_CLIENT_SRC_FILES})

target_link_libraries(FQL_CLIENT FQL_CORE_LIB)

set_property(TARGET FQL_CLIENT PROPERTY CXX_STANDARD 17)
