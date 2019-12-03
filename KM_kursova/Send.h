#ifndef _SEND_H_
#define _SEND_H_

#include "global_value.h"
#include "Package.h"
#include "Channel.h"

class Send
{
public:
    Send() {}
    Send(Message& message, std::vector<std::vector<Node*>>& listOfpath, enumTypeOfSend typeOfSend)
    {
        typeOfSend_ = typeOfSend;
        switch (typeOfSend_)
        {
        case Datagram:
            DatagramSend(message, listOfpath); break;
        case Logic: 
            LogicSend(message, listOfpath); break;
        case Virtual :
            VirtualSend(message, listOfpath); break;
        default:
            break;
        }
    }
    void DatagramSend(Message& message, std::vector<std::vector<Node*>>& listOfpath)
    {
        /*added information in text*/
    }
    void LogicSend(Message& message, std::vector<std::vector<Node*>>& listOfpath)
    {

    }
    void VirtualSend(Message& message, std::vector<std::vector<Node*>>& listOfpath)
    {

    }
protected:

private:
    enumTypeOfSend typeOfSend_;
};

#endif // !_SEND_H_
