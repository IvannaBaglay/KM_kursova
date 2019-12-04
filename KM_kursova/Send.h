#ifndef _SEND_H_
#define _SEND_H_

#include "global_value.h"
#include "Package.h"
#include "Channel.h"

class Send
{
public:
    Send() {}
    Send(Message* message, std::vector<std::vector<Node*>>& listOfPath, enumTypeOfSend typeOfSend)
    {
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
    void DatagramSend(Message* message, std::vector<std::vector<Node*>>& listOfPath)
    {
        int numberOfMessage = message->get_numberOfPackage();
        for (int i = 0; i < numberOfMessage; i++)
        {
            (*message)[i]->set_addedInformation(std::to_string(message->get_indexOfDestinationNode()));
        }
        for (int i = 0; i < numberOfMessage; i++)
        {
            auto currentListOfPath = listOfPath[i];
            for (auto itNode : currentListOfPath)
            {
                itNode->set_haveAddedInformation(true);
                std::pair<std::string, std::string> pair(std::to_string(message->get_indexOfDestinationNode()), std::to_string(itNode->get_predecessor()));
                itNode->AddInformation(pair);
            }
        }
        /*added information in text*/
    }
    void LogicSend(Message* message, std::vector<std::vector<Node*>>& listOfPath)
    {
        int numberOfMessage = message->get_numberOfPackage();
        for (int i = 0; i < numberOfMessage; i++)
        {
            (*message)[i]->set_addedInformation(std::to_string(message->get_indexOfDestinationNode()));
        }
        /**/
        for (int i = 0; i < numberOfMessage; i++)
        {
            auto currentListOfPath = listOfPath[i];
            for (auto itNode : currentListOfPath)
            {
                itNode->set_haveAddedInformation(true);
                std::pair<std::string, std::string> pair(std::to_string(message->get_indexOfDestinationNode()), std::to_string(itNode->get_predecessor()));
                itNode->AddInformation(pair);
            }
        }
    }
    void VirtualSend(Message* message, std::vector<std::vector<Node*>>& listOfPath)
    {
        /*ôóíêö³ÿ */
        auto virtualChannel = FindVirtualChannel(listOfPath);


        int numberOfMessage = message->get_numberOfPackage();
        int i = 0;
        for (auto it = virtualChannel.begin(); it != virtualChannel.end(); it++)
        {
            for (auto itNode : it->second)
            {
                (*message)[itNode]->set_addedInformation((std::to_string(message->get_indexOfDestinationNode()), std::to_string(i)));
            }
            i++;
        }
        i = 0;
        for (auto it = virtualChannel.begin(); it != virtualChannel.end(); it++)
        {
            for (auto itPath : it->first)
            {
                itPath->set_haveAddedInformation(true);
                std::pair<std::string, std::string> pair(std::to_string(message->get_indexOfDestinationNode()), std::to_string(i));
                itPath->AddInformation(pair);
            }
            i++;
        }
    }
    std::map<std::vector<Node*>, std::vector<int>> FindVirtualChannel(std::vector<std::vector<Node*>>& listOfPath)
    {
        std::map<std::vector<Node*>, std::vector<int>> mapOfVirtualVector;
        int i = 0;
        int j = 0;
        for (auto it1 : listOfPath)
        {
            mapOfVirtualVector[it1].push_back(i);
            i++;
        }
        for (auto it = mapOfVirtualVector.begin(); it != mapOfVirtualVector.end(); it++)
        {
            for (auto itNode : it->second)
            {
                std::cout << itNode << "\t";
            }
            std::cout << std::endl;
            i++;
        }
        return mapOfVirtualVector;
    }
protected:

private:
    enumTypeOfSend typeOfSend_;
};

#endif // !_SEND_H_
