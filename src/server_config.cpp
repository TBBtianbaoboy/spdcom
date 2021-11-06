#include "../include/server_config.h"
#include "../include/utils.h"
#include <cstdlib>
#include <exception>
#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;
using ifstream = std::ifstream;
using spdcom::argusChecker;
using spdcom::argusType;
using spdcom::globalData;

json configMap;
void spdcom::readConfigJson(){
    ifstream fin("/home/aico/github/spdcom/conf/config.json");
    fin>>configMap;
    fin.close();
    std::cout << configMap["server_port"] << std::endl;
}

globalData global_data;
argusChecker spdcom::parseCLA(const int argc,  char **argv){
    if (1 == argc){
        return argusChecker::NOARGUS;
    }
    int argcBack = argc - 1;
    while(argcBack!=0){
        switch(spdcom::tools::isInArguList(argv[argc-argcBack])){
            case argusType::COMMAND:
                if(--argcBack!=0){
                    if(spdcom::tools::isInArguList(argv[argc-argcBack-1])!=argusType::OTHERS){
                        global_data.command = argv[argc-argcBack];
                        --argcBack;
                    }
                    else
                        return argusChecker::NOARGUSVALUE;
                }
                else 
                    return argusChecker::NOARGUSVALUE;
                break;
            case argusType::OTHERS:
                return argusChecker::ARGUSERROR;
        }
    }
    return argusChecker::SUCCESS;
}

const string& spdcom::handleParseCLA(const int argc, char **argv){
    switch(spdcom::parseCLA(argc,argv)){
        case argusChecker::ARGUSERROR:
            return spdcom::argus_error;
        case argusChecker::NOARGUSVALUE:
            return spdcom::no_argus_value;
        case argusChecker::NOARGUS:
            return spdcom::no_argus;
        case argusChecker::SUCCESS:
            return spdcom::OK;
    }
    return spdcom::OK;
}
