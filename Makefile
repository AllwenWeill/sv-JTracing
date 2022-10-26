INCLUDE_PATH = include/preprocessing/
SRC_PATH = source/main.cpp
SRC_PATH += source/preprocessing/SourceManager.cpp

OFILE = main.o SourceManager.o

Q = @
COMPILE = /usr/bin/
CC = ${Q}${COMPILE}gcc-9
CXX = ${Q}${COMPILE}g++-9
SIZE = ${Q}${COMPILE}size
CFLAGS = -Wall '-std=c++17' -g

LDFLAGS = -I${INCLUDE_PATH}
CXXFLAGS = -I${INCLUDE_PATH} ${CFLAGS}

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

.PHONY : clean
clean :
	${ECHO} "cleaning"
	rm *.o ${TAR}
