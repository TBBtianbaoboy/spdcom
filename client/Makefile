HOST_SYSTEM = $(shell uname | cut -f 1 -d_)
SYSTEM ?= $(HOST_SYSTEM)
CXX = g++
CPPFLAGS += `pkg-config --cflags protobuf grpc`
INCLUDEFILE=-I ../include
CXXFLAGS += -std=c++11
ifeq ($(SYSTEM),Darwin)
LDFLAGS += -L/usr/local/lib `pkg-config --libs protobuf grpc++`\
           -pthread\
           -lgrpc++_reflection\
           -ldl
else
LDFLAGS += -L/usr/local/lib `pkg-config --libs protobuf grpc++`\
           -pthread\
           -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed\
           -ldl
endif
OBJ= execute_command.pb.o execute_command.grpc.pb.o client.o server_config.o client_caller.o utils.o
CLIENTPATH=../rpcclient

vpath %.cpp ../src

all: $(OBJ)
	$(CXX) $^ $(LDFLAGS) -o $(CLIENTPATH)

.PRECIOUS:%.o
%.o:%.cpp 
	$(CXX) $(INCLUDEFILE) -c -o $@ $<

.PHONY: clean
clean:
	rm -f *.o ../rpcclient
