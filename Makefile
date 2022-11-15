INCLUDE_PATH = -I./include/preprocessing/
INCLUDE_PATH += -I./include/parsing/
INCLUDE_PATH += -I./include/utility/
INCLUDE_PATH += -I./include/syntax/

SRC_PATH = source/main.cpp
SRC_PATH += source/preprocessing/SourceManager.cpp
SRC_PATH += source/parsing/Lexer.cpp
SRC_PATH += source/parsing/Token.cpp

OFILE = main.o SourceManager.o Lexer.o Token.o

Q = @
COMPILE = /usr/bin/
CC = ${Q}${COMPILE}gcc-9
CXX = ${Q}${COMPILE}g++-9
SIZE = ${Q}${COMPILE}size
CFLAGS = -Wall '-std=c++17' -g

LDFLAGS = ${INCLUDE_PATH}
CXXFLAGS = ${INCLUDE_PATH} ${CFLAGS}

ECHO = ${Q}echo

TAR = svj
 
svj: ${OFILE}
	${ECHO} "making ${TAR}!!"
	${CXX} ${LDFLAGS} ${OFILE} -o ${TAR}
	${SIZE} ${TAR}

main.o: source/main.cpp
	${ECHO} "cxx main.cpp"
	${CXX} ${CXXFLAGS} -c source/main.cpp -o main.o

SourceManager.o: source/preprocessing/SourceManager.cpp
	${ECHO} "cxx SourceManager.cpp"
	${CXX} ${CXXFLAGS} -c source/preprocessing/SourceManager.cpp -o SourceManager.o

Lexer.o: source/parsing/Lexer.cpp
	${ECHO} "cxx Lexer.cpp"
	${CXX} ${CXXFLAGS} -c source/parsing/Lexer.cpp -o Lexer.o

Token.o: source/parsing/Token.cpp
	${ECHO} "cxx Token.cpp"
	${CXX} ${CXXFLAGS} -c source/parsing/Token.cpp -o Token.o

.PHONY : clean
clean :
	${ECHO} "cleaning"
	rm *.o ${TAR}