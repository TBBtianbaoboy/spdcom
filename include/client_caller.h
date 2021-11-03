#pragma once
#include "execute_command.pb.h"
#include "nlohmann/json.hpp"
#include <grpcpp/channel.h>
#include <grpcpp/security/credentials.h>
#include <memory>
#include <mutex>
#include <string>
#include "grpcpp/grpcpp.h"
#include "utils.h"
#include "../include/execute_command.grpc.pb.h"

using string = std::string;
using json   = nlohmann::json;

using grpc::Channel;
using grpc::Status;
using grpc::ClientContext;
using grpc::ChannelCredentials;

using ec::CommandReq;
using ec::CommandResp;
using ec::ExecuteCommand;

namespace spdcom{

    class ClientCaller{
        public:
            ClientCaller(std::shared_ptr<ChannelCredentials> channelCredentials);
            ~ClientCaller();
            ClientCaller(const ClientCaller&)=delete;
            ClientCaller& operator=(const ClientCaller&)=delete;
            ClientCaller(ClientCaller&&);

            //获取服务端的ip:port
            string getServerIpAndPort()const;

        protected:
            string serverAddress;
            CommandReq req;
            CommandResp resp;
            ClientContext context;
            Status status;
            std::shared_ptr<Channel> channel;
    };

    class ExecuteCommandClient final:public ClientCaller{
        private:
            std::unique_ptr<ExecuteCommand::Stub> stub_;
        public:
            ExecuteCommandClient(std::shared_ptr<ChannelCredentials> channelCredentials=grpc::InsecureChannelCredentials());
            string sendReq(const string&);
    };
}
