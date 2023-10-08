//
// Created by Leafylotus on 10/7/2023.
//

#ifndef ASSBAG_PLAINBAG_H
#define ASSBAG_PLAINBAG_H

#include "BagInterface.h"

template<typename T>
class PlainBag : public  BagInterface<T> {
public:
    PlainBag();
    void insert(T);
    bool remove(T);
    int itemCount(T);
    bool hasItem(T);
    void clear();
    int size();
    bool isEmpty();
    bool isFull();
    void print();
    ~PlainBag(){};
private:
    T* m_data;
    int m_size;
    int m_capacity;
    void resize();
    void removeByIndex(int);
};


#endif //ASSBAG_PLAINBAG_H
