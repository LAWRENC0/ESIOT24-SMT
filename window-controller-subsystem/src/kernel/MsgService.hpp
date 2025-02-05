#ifndef __MSGSERVICE__
#define __MSGSERVICE__

#include "Arduino.h"

class Msg {
    String content;

   public:
    Msg(String content) { this->content = content; }

    String getContent() { return content; }
};

class MsgServiceClass {
   public:
    Msg* currentMsg;
    bool msgAvailable;

    void init(int baud_rate);

    bool isMsgAvailable();
    Msg* receiveMsg();

    void sendMsg(const String& msg);

    bool checkStartMessage(const String& msg);
};

extern MsgServiceClass MsgService;

#endif