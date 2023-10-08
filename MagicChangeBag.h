//
// Created by Leafylotus on 10/7/2023.
//

#ifndef ASSBAG_MAGICCHANGEBAG_H
#define ASSBAG_MAGICCHANGEBAG_H

#include "BagInterface.h"

template<typename T>
class MagicChangeBag : public  BagInterface<T> {
public:
    MagicChangeBag();
    void insert(T);
    bool remove(T);
    int itemCount(T);
    bool hasItem(T);
    void clear();
    int size();
    bool isEmpty();
    bool isFull();
    void print();
    ~MagicChangeBag(){};
private:
    T* m_data;
    int m_size;
    int m_capacity;
    void resize();
    void removeByIndex(int);
};



#endif //ASSBAG_MAGICCHANGEBAG_H
