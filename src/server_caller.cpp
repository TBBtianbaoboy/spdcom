#include "../include/server_caller.h"
#include "../include/utils.h"
#include <cstdlib>
#include <exception>
#include <iostream>

using spdcom::ServerCaller;
using spdcom::ExecuteCommandService;

using spdcom::tools;

extern json configMap;

Status ExecuteCommandService::sendReq(ServerContext* context,const CommandReq* req,CommandResp* resp){
    auto command = req->command();
    resp->set_commandresult(tools::getCommandResult(command)); 
    return Status::OK;
}

ServerCaller::ServerCaller():serverAddress(),builder(),service(),server(){
    serverAddress = configMap["server_ip"];
    serverAddress.append(":");
    serverAddress += configMap["server_port"];
    builder.AddListeningPort(serverAddress,grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<Server> server_back(builder.BuildAndStart());
    server = std::move(server_back);
}

ServerCaller::~ServerCaller(){
}

//TODO
ServerCaller::ServerCaller(ServerCaller&& cal){

}

string ServerCaller::GetServerAddress()const{
    return serverAddress; 
}

void ServerCaller::Wait()const{
    server->Wait();
}


