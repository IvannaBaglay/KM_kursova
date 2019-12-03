#ifndef _PACKAGE_H_
#define _PACKAGE_H_

#include "Node.h";

class Package {
public:
    Package(){}
    Package(int index,  int size, std::string addedInformation)
    {
        index_ = index;
        addedInformation_ = addedInformation;
        sizeOfPackage_ = size;
        /*Added function for added Information*/
    }
    const int get_index() const
    {
        return index_;
    }
    const std::string get_addedInformation() const
    {
        return addedInformation_;
    }
    void set_addedInformation(std::string information)
    {
        addedInformation_ = information;
    }
    const int get_sizeOfPackage() const
    {
        return sizeOfPackage_;
    }
    const int get_sizeOfAddedInformation() const 
    {
        return sizeOfAddedInformation_;
    }

protected:

private:
    int index_;
    int sizeOfPackage_;
    int sizeOfAddedInformation_;
    std::string addedInformation_; //  in virtual send have information about virtual channel
                                    // in datagram have index of destination node
};

class Message {
public:
    Message(int lenghtOfMessage, int sizeOfPackage, int indexOfDestinationNode)
    {
        lenghtOfMessage_ = lenghtOfMessage;
        if (lenghtOfMessage_ % sizeOfPackage)
        {
            numberOfPackage_ = lenghtOfMessage_ / sizeOfPackage + 1;
        }
        else
        {
            numberOfPackage_ = lenghtOfMessage_ / sizeOfPackage;
        }
        for (int i = 1; i <= numberOfPackage_; i++)
        {
            
            listOfPackage_.push_back(new Package(i, sizeOfPackage, ""));
        }
    }
protected:

private:
    int lenghtOfMessage_;
    int numberOfPackage_;
    std::vector<Package*> listOfPackage_;
};

#endif // !_PACKAGE_H_

