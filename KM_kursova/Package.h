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
    Message(int lenghtOfMessage, int sizeOfPackage)
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
    void set_indexOfDestinationNode(int index)
    {
        indexOfDestinationNode_ = index;
    }
    const int get_numberOfPackage() const
    {
        return numberOfPackage_;
    }

    const int get_indexOfDestinationNode() const
    {
        return indexOfDestinationNode_;
    }
    
    Package* &operator[](int index)
    {
        if (index < numberOfPackage_)
        {
            return listOfPackage_[index];
        }
    }
protected:

private:
    int indexOfDestinationNode_;
    int lenghtOfMessage_;
    int numberOfPackage_;
    std::vector<Package*> listOfPackage_;
};

#endif // !_PACKAGE_H_

