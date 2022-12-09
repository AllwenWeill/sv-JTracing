# CMakeList.txt: sv-JTracing 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("sv-JTracing")

# 将源代码添加到此项目的可执行文件。
add_subdirectory (source)

include_directories (./include/parsing/ ./include/preprocessing ./include/syntax ./include/utility ./include/ast ./include/handlMessage)

add_executable (sv-JTracing "source/main.cpp" "sv-JTracing.h"  "source/parsing/Lexer.cpp" "include/parsing/Lexer.h" "include/parsing/keywordsDefine.h" "include/parsing/Token.h" "include/parsing/TokenKind.h" "source/parsing/TokenKind.cpp" "include/utility/allinclude.h" "include/utility/Allocator.h" "include/preprocessing/SourceManager.h" "include/syntax/SyntaxNode.h" "source/parsing/Token.cpp" "source/preprocessing/SourceManager.cpp" "source/utility/Allocator.cpp" "include/parsing/Parser.h" "source/parsing/Parser.cpp" "include/handlMessage/LogError.h" "source/handlMessage/LogError.cpp" "include/ast/BeginAST.h" "include/handlMessage/LogParser.h" "source/handlMessage/LogParser.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET sv-JTracing PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。
