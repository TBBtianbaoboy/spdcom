#include <iostream>
#include "../include/server_config.h"
#include "../include/server_caller.h"
using std::string;

int main(int argc, char *argv[]) {
    readConfigJson();
    spdcom::ServerCaller server;
    std::cout << "server listening on : " << server.GetServerAddress() << std::endl;
    server.Wait();
    return 0;
}
