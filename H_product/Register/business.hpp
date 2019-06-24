#ifndef BUSINESS_HPP_
#define BUSINESS_HPP_
#include"global.hpp"
#include"hhmii.hpp"
#include"hhmsi.hpp"
const  int Auth=1;
typedef void (*THCmdResponder)(string &Context);

//mq回调

typedef void (*THMsgResponder)(const string &cmd, const string text);
typedef void (*THMsgRecv)(const string text);
//注册Re服务，int类型命令，回调执行
//Dis分发命令，携带context类型数据
extern bool RegisterCommandHandler(const int cmd, THCmdResponder Responder);
extern bool DispatchCommand(string & Context, const int cmd);
//mq信息注册和分发

extern bool RegisterMsgRecv(const string cmd,THMsgRecv recv);
extern bool DispathMsgS(const string cmd, const string text);
//extern bool RegisterMsgHandler(const string cmd, THMsgResponder Responder);
#endif
