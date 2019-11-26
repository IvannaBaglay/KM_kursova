#ifndef _CHANNEL_H_
#define _CHANNEL_H_

#define DUPLEX 0
#define HALF_DUPLEX 1

class Channel {
public:
    const unsigned int get_weight() const {
        return weight;
    }
    const unsigned int get_type() const {
        return type;
    }
    /*
    function for display info when we select channel with mouse
    */
protected:

private:
    int weight;
    unsigned int type;
};

#endif // !_CHANNEL_H_
