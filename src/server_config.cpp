#include "../include/server_config.h"
#include <cstdlib>
#include <exception>
#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;
using ifstream = std::ifstream;

json configMap;

// namespace spd{
void readConfigJson(){
    ifstream fin("/home/aico/github/spdcom/conf/config.json");
    fin>>configMap;
    fin.close();
    std::cout << configMap["server_ip"] << std::endl;
    std::cout << configMap["server_port"] << std::endl;
}
// }
