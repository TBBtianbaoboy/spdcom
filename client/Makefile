CXX=g++
CXXFLAGS=-O2 -Wall 
INCLUDEFILE=-I ../include
DLL=-lrpc -lpthread
PROJECT=client
TARGET=../clientelf

all: ${PROJECT}

${PROJECT}:client.o server_config.o client_caller.o utils.o
	${CXX} ${CXXFLAGS} ${INCLUDEFILE} -o ${TARGET} $^ ${DLL}

client.o:client.cpp
	${CXX} -c ${INCLUDEFILE} $<

server_config.o:../src/server_config.cpp
	${CXX} -c ${INCLUDEFILE} $<

client_caller.o:../src/client_caller.cpp
	${CXX} -c ${INCLUDEFILE} $<

utils.o:../src/utils.cpp
	${CXX} -c ${INCLUDEFILE} $<

clean:
	rm -f *.o ${TARGET} 

