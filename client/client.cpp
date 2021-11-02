#include <iostream>
#include "dbg.h"
// #include "client_caller.h"
// #include "server_config.h"

#include "../include/client_caller.h"
#include "../include/server_config.h"

using spdcom::Caller;

int main() {
    readConfigJson();
    Caller caller;
    dbg(caller.getLs());
    // auto result2 = client.call("ls","ls -l").as<std::string>();
    return 0;
}
