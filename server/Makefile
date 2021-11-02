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
PROTOC = protoc
GRPC_CPP_PLUGIN = grpc_cpp_plugin
GRPC_CPP_PLUGIN_PATH ?= `which $(GRPC_CPP_PLUGIN)`
OBJ= execute_command.pb.o execute_command.grpc.pb.o server.o server_config.o server_caller.o utils.o
PROTOS_PATH = ../protos

vpath %.proto $(PROTOS_PATH)
vpath %.cpp ../src

all: 
	cd ../include && make
	make rpcserver

rpcserver: $(OBJ)
	$(CXX) $(INCLUDEFILE) $^ $(LDFLAGS) -o $@

.PRECIOUS:%.o
%.o:%.cpp 
	$(CXX) $(INCLUDEFILE) -c -o $@ $<

.PHONY: clean
clean:
	cd ../include && make clean
	rm -f *.o rpcserver
