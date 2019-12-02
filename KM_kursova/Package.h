#ifndef _PACKAGE_H_
#define _PACKAGE_H_

#include "Node.h";

class Package {
public:
    Package(){}
    Package(int index, int indexOfDestinationNode, std::string addedInformation)
    {
        index_ = index;
        indexOfDestinationNode_ = indexOfDestinationNode;
    }
    const int get_index() const
    {
        return index_;
    }
    const int get_indexOfDestinationNode() const
    {
        return indexOfDestinationNode_;
    }

protected:

private:
    int index_;
    int indexOfDestinationNode_;
    std::string addedInformation_;
};

#endif // !_PACKAGE_H_

