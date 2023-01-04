SVJ_PATH = .

INCLUDE_PATH = -I${SVJ_PATH}/include/preprocessing/ \
-I${SVJ_PATH}/include/parsing/ \
-I${SVJ_PATH}/include/utility/ \
-I${SVJ_PATH}/include/syntax/ \
-I${SVJ_PATH}/include/ast/ \
-I${SVJ_PATH}/include/handlMessage/ \

SRC_PATH = ${SVJ_PATH}/source/main.cpp \
${SVJ_PATH}/source/preprocessing/SourceManager.cpp \
${SVJ_PATH}/source/parsing/Lexer.cpp \
${SVJ_PATH}/source/parsing/Token.cpp \
${SVJ_PATH}/source/parsing/TokenKind.cpp \
${SVJ_PATH}/source/parsing/Parser.cpp \
${SVJ_PATH}/source/handlMessage/LogError.cpp \
${SVJ_PATH}/source/handlMessage/LogParser.cpp

OFILE = $(patsubst %.cpp,%.o,$(SRC_PATH))

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
	${CXX} ${LDFLAGS} -o $@ $^
	${SIZE} ${TAR}

${OFILE}: ${SRC_PATH}
	${ECHO} "cxx $@"
	${CXX} ${CXXFLAGS} -c $(patsubst %.o,%.cpp,$@) -o $@ 

.PHONY : clean
clean :
	${ECHO} "cleaning"
	rm ${OFILE} ${TAR}