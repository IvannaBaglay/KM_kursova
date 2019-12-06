#ifndef _SEND_H_
#define _SEND_H_

#include "global_value.h"
#include "Package.h"
#include "Channel.h"

class Send
{
public:
    Send() { numberOfVirtualChannel = 0; }
    void SendPackage(Package* message, std::vector<Node*>& listOfPath, enumTypeOfSend typeOfSend)
    {
       
        std::cout << "\n\nPath: ";
        for (auto it : listOfPath)
        {
            std::cout << it->get_index();
        }
        typeOfSend_ = typeOfSend;
        switch (typeOfSend_)
        {
        case Datagram:
            DatagramSend(message, listOfPath); break;
        case Logic: 
            LogicSend(message, listOfPath); break;
        case Virtual :
            VirtualSend(message, listOfPath); break;
        default:
            break;
        }
    }
    void DatagramSend(Package* message, std::vector<Node*>& listOfPath)
    {    
        message->set_addedInformation(std::to_string(message->get_nodeDestination())); // end Node          
        for (auto itNode : listOfPath)
        {
           itNode->set_haveAddedInformation(true);
            std::pair<std::string, std::string> pair(message->get_addedInformation(), std::to_string(itNode->get_predecessor()));
            itNode->AddInformation(pair);
        }
        /*added information in text*/
    }
    void LogicSend(Package* message, std::vector<Node*>& listOfPath)
    {
        message->set_addedInformation(std::to_string(message->get_nodeDestination())); // end Node          

        for (auto itNode : listOfPath)
        {
            itNode->set_haveAddedInformation(true);
            std::pair<std::string, std::string> pair(message->get_addedInformation(), std::to_string(itNode->get_predecessor()));
            itNode->AddInformation(pair);
        }
    }
    void VirtualSend(Package* message, std::vector<Node*>& listOfPath)
    {
        message->set_addedInformation(std::to_string(message->get_nodeDestination())); // end Node 
        
        int index = FindVirtualNode(listOfPath);
        if (index == -1)
        {
            listNodeInVirtualChannel.push_back(listOfPath);
            index = numberOfVirtualChannel++;
        }
        for (auto itPath :listOfPath)
        {
            std::cout << itPath->get_index();
            itPath->set_haveAddedInformation(true);
            std::pair<std::string, std::string> pair(message->get_addedInformation(), std::to_string(index));
            itPath->AddInformation(pair);
        }
    }
    int FindVirtualNode(std::vector<Node*>& listOfPath)
    {
        int i = 0;
        for (auto it : listNodeInVirtualChannel)
        {
            if (it == listOfPath)
            {
                return i;
            }
            i++;
        }
        return -1;
    }
protected:

private:
    int numberOfVirtualChannel;
    std::vector< std::vector<Node*>> listNodeInVirtualChannel;
    enumTypeOfSend typeOfSend_;
};

#endif // !_SEND_H_
