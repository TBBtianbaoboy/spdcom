#include "../include/utils.h"
#include "../include/const.h"
#include <bits/types/FILE.h>
#include <cerrno>
#include <cstdio>
#include <cstring>
#include <string>
#include <unistd.h>

using std::string;
using spdcom::MESSAGESIZEF;
using spdcom::tools;
using spdcom::argusType;

string tools::getCommandResult(string& command){
    FILE *fstream = nullptr;
    char buff[MESSAGESIZEF];
    memset(buff,0,sizeof(buff));
    if (nullptr==(fstream=popen(command.c_str(),"r"))){
        fprintf(stderr,"execute command failed: %s",strerror(errno));
        return "command execute failed: "+ string(strerror(errno));
    }
    while(nullptr!=fgets(buff,sizeof(buff),fstream)){
    }
    pclose(fstream);
    return buff;
}

const string tools::getCurrentPwd(){
    return string(get_current_dir_name());
}

argusType tools::isInArguList(string argu){
    if(argu=="-c" || argu=="--command"){
        return COMMAND;
    }
    return OTHERS;
}
