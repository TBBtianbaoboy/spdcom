#include <iostream>
#include "dbg.h"

#include "../include/client_caller.h"
#include "../include/server_config.h"

using spdcom::ExecuteCommandClient;

int main() {
    readConfigJson();
    ExecuteCommandClient commandCaller;
    dbg(commandCaller.sendReq("ls -l"));
    return 0;
}
