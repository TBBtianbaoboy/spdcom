#include "../include/client_caller.h"
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>
#include <memory>

using spdcom::ClientCaller;
using spdcom::ExecuteCommandClient;


extern json configMap;

//client_caller init 
ClientCaller::ClientCaller(std::shared_ptr<ChannelCredentials> channelCredentials):req(),resp(),context(),status(),serverAddress(),channel(){
    serverAddress.append(configMap["server_ip"]).append(":").append(configMap["server_port"]);
    channel = grpc::CreateChannel(serverAddress,channelCredentials); 
}

//client_caller dcon
ClientCaller::~ClientCaller(){}

ExecuteCommandClient::ExecuteCommandClient(std::shared_ptr<ChannelCredentials> channelCredentials):ClientCaller(channelCredentials),stub_(ExecuteCommand::NewStub(channel)){
}

string ExecuteCommandClient::sendReq(const string &command){
    req.set_command(command);
    status = stub_->sendReq(&context,req,&resp);
    if(status.ok()){
        return resp.commandresult();
    }
    return "RPC failed";
}

