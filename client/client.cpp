#include <iostream>
#include "dbg.h"

#include "../include/client_caller.h"
#include "../include/server_config.h"

using spdcom::ExecuteCommandClient;

extern spdcom::globalData global_data;

int main(int argc,char** argv) {
    std::cout << argc << std::endl;

    spdcom::readConfigJson();
    auto CLAresult = spdcom::handleParseCLA(argc,argv); 
    if(CLAresult!=spdcom::OK){
        std::cout << CLAresult << std::endl;
        return -1;
    }
    ExecuteCommandClient commandCaller;
    dbg(commandCaller.sendReq(global_data.command));
    return 0;
}
