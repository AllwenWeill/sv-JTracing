INCLUDE_PATH = "/home/allwen66/ws/sv-JTracing/include/preprocessing/"
SRC_PATH = "source/*.cpp"
SRC_PATH += "source/preprocessing/*.cpp"

CC = /usr/bin/gcc-9
CXX = /usr/bin/g++-9
CFLAGS = -Wall '-std=c++17' -g

TAR = svj
 
svj: main.o SourceManager.o
	echo "making ${TAR}!!"
	${CXX} -I${INCLUDE_PATH} main.o SourceManager.o -o ${TAR}

main.o: source/main.cpp
	${CXX} -I${INCLUDE_PATH} ${CFLAGS} -c source/main.cpp -o main.o

SourceManager.o: source/preprocessing/SourceManager.cpp
	${CXX} -I${INCLUDE_PATH} ${CFLAGS} -c source/preprocessing/SourceManager.cpp -o SourceManager.o

.PHONY : clean
clean :
	echo "cleaning"
	rm *.o ${TAR}
