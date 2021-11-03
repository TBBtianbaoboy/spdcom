CXX = g++
CPPFLAGS += `pkg-config --cflags protobuf grpc`
CXXFLAGS += -std=c++11

PROTOC = protoc
GRPC_CPP_PLUGIN = grpc_cpp_plugin
GRPC_CPP_PLUGIN_PATH ?= `which $(GRPC_CPP_PLUGIN)`

PROTOS_PATH = ../protos

vpath %.proto $(PROTOS_PATH)

all: execute_command.pb.o execute_command.grpc.pb.o
	@cp execute_command.pb.o ../server/
	@cp execute_command.pb.o ../client/
	@cp execute_command.grpc.pb.o ../server/
	@cp execute_command.grpc.pb.o ../client/

.PRECIOUS: %.grpc.pb.cc
%.grpc.pb.cc: %.proto
	$(PROTOC) -I $(PROTOS_PATH) --grpc_out=. --plugin=protoc-gen-grpc=$(GRPC_CPP_PLUGIN_PATH) $<

.PRECIOUS: %.pb.cc
%.pb.cc: %.proto
	$(PROTOC) -I $(PROTOS_PATH) --cpp_out=. $<

.PHONY: clean
clean:
	rm -fr *.o ./execute_command.pb.h ./execute_command.pb.cc ./execute_command.grpc.pb.h ./execute_command.grpc.pb.cc

