// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: execute_command.proto

#include "execute_command.pb.h"
#include "execute_command.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace ec {

static const char* ExecuteCommand_method_names[] = {
  "/ec.ExecuteCommand/sendReq",
};

std::unique_ptr< ExecuteCommand::Stub> ExecuteCommand::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< ExecuteCommand::Stub> stub(new ExecuteCommand::Stub(channel, options));
  return stub;
}

ExecuteCommand::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_sendReq_(ExecuteCommand_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status ExecuteCommand::Stub::sendReq(::grpc::ClientContext* context, const ::ec::CommandReq& request, ::ec::CommandResp* response) {
  return ::grpc::internal::BlockingUnaryCall< ::ec::CommandReq, ::ec::CommandResp, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_sendReq_, context, request, response);
}

void ExecuteCommand::Stub::async::sendReq(::grpc::ClientContext* context, const ::ec::CommandReq* request, ::ec::CommandResp* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::ec::CommandReq, ::ec::CommandResp, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_sendReq_, context, request, response, std::move(f));
}

void ExecuteCommand::Stub::async::sendReq(::grpc::ClientContext* context, const ::ec::CommandReq* request, ::ec::CommandResp* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_sendReq_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::ec::CommandResp>* ExecuteCommand::Stub::PrepareAsyncsendReqRaw(::grpc::ClientContext* context, const ::ec::CommandReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::ec::CommandResp, ::ec::CommandReq, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_sendReq_, context, request);
}

::grpc::ClientAsyncResponseReader< ::ec::CommandResp>* ExecuteCommand::Stub::AsyncsendReqRaw(::grpc::ClientContext* context, const ::ec::CommandReq& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncsendReqRaw(context, request, cq);
  result->StartCall();
  return result;
}

ExecuteCommand::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ExecuteCommand_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ExecuteCommand::Service, ::ec::CommandReq, ::ec::CommandResp, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](ExecuteCommand::Service* service,
             ::grpc::ServerContext* ctx,
             const ::ec::CommandReq* req,
             ::ec::CommandResp* resp) {
               return service->sendReq(ctx, req, resp);
             }, this)));
}

ExecuteCommand::Service::~Service() {
}

::grpc::Status ExecuteCommand::Service::sendReq(::grpc::ServerContext* context, const ::ec::CommandReq* request, ::ec::CommandResp* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace ec
