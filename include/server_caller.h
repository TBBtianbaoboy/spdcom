#pragma once
#include "nlohmann/json.hpp"
#include <grpcpp/completion_queue.h>
#include <grpcpp/server.h>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>
#include "utils.h"
#include "execute_command.grpc.pb.h"

using string = std::string;
using json   = nlohmann::json;

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using ec::ExecuteCommand;
using ec::CommandReq;
using ec::CommandResp;


namespace spdcom{
    //@desc 实际跑起来的服务
    class ExecuteCommandService final:public ExecuteCommand::Service{
        Status sendReq(ServerContext* ,const CommandReq*, CommandResp*)override;
    };

    //@desc server controller
    class ServerCaller{
        public:
            ServerCaller();
            ~ServerCaller();
            ServerCaller(const ServerCaller&)=delete;
            ServerCaller& operator=(const ServerCaller&)=delete;
            ServerCaller(ServerCaller&&);
            string GetServerAddress()const;
            void Wait()const;


            // @abandon:don't want to use tcp rpc
            // template<typename T,typename... Args>
            //     T call(string funcName,Args... args)const{
            //         return client->call(funcName,args...).template as<T>();
            //     }

        private:
            string serverAddress;
            ServerBuilder builder;
            ExecuteCommandService service;
            std::unique_ptr<Server> server;
    };
}
