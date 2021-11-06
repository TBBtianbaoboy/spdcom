#pragma once
#include <string>
using std::string;


namespace spdcom{
// CLA 状态检查器
typedef enum argusChecker{
    NOARGUS, //没有参数
    SUCCESS,  //成功
    NOARGUSVALUE, //没有参数值
    // ARGUSVALUEERROR,//参数值错误
    ARGUSERROR //参数错误
}argusChecker;

// 全局信息储存
typedef struct globalData{
    string command;
}globalData;

// 参数类型匹配
typedef enum argusType{
    COMMAND,//0
    OTHERS  //1
}argusType;

const string no_argus = "请添加相应的参数来执行指定的操作";
const string OK = "";
const string no_argus_value = "存在参数无值，请再次确认请求参数";
const string argus_error = "参数存在错误，请再次确认请求参数";
    //@desc 读取配置文件
    void readConfigJson();
    //@desc 解析CLA 行为
    argusChecker parseCLA(const int,char**);
    //@desc 格式化处理CLA 行为
    const string& handleParseCLA(const int,char**);
}

