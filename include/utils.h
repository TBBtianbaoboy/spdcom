//@desc utils.h encapsulates some common tools
#pragma once
#include <string>
#include "server_config.h"
using std::string;

namespace spdcom{
    class tools{
        public:
            tools()=delete;
            tools(const tools&)=delete;
            tools& operator=(const tools&)=delete;
            ~tools()=delete;
            tools(tools&&)=delete;

        public:
            static string getCommandResult(string&);
            static const string getCurrentPwd();
            static argusType isInArguList(string);
    };
}
