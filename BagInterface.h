//
// Created by Leafylotus on 10/7/2023.
//

#ifndef ASSBAG_BAGINTERFACE_H
#define ASSBAG_BAGINTERFACE_H



template <typename T>
class BagInterface {
public:
    virtual void insert(T) = 0;
    virtual bool remove(T) = 0;
    virtual int itemCount(T) = 0;
    virtual bool hasItem(T) = 0;
    virtual void clear() = 0;
    virtual int size() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual void print() = 0;
private:
    virtual void resize() = 0;
    virtual void removeByIndex(int) = 0;
};



#endif //ASSBAG_BAGINTERFACE_H
