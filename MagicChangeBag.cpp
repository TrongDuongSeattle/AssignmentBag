#include "MagicChangeBag.h"
#include <iostream>


template <typename T>
MagicChangeBag<T>::MagicChangeBag() {
    m_data = new T[20];
    m_size = 0;
    m_capacity = 20;
}


template <typename T>
void MagicChangeBag<T>::insert(T value) {
    if (m_capacity == m_size) {
        resize();
    }
    m_data[m_size] = value;
    m_size++;
}

template <typename T>
bool MagicChangeBag<T>::remove(T value) {
    int num = 0;
    for (int i = 0; i < m_size; i++) {
        if (m_data[i] == value) {
            removeByIndex(num);
            break;
        }
        num++;
    }
    return -1;
}

template <typename T>
int MagicChangeBag<T>::itemCount(T value) {
    int count = 0;
    for (int i = 0; i < m_size; i++) {
        if (m_data[i] == value) {
            count++;
        }
    }
    return count;
}

template <typename T>
bool MagicChangeBag<T>::hasItem(T value) {
    for (int i = 0; i < m_size; i++) {
        if (m_data[i] == value) {
            return true;
        }
    }
    return false;
}

template <typename T>
int MagicChangeBag<T>::size() {
    return 0;
}

template <typename T>
void MagicChangeBag<T>::clear() {
    m_size = 0;
}

template <typename T>
bool MagicChangeBag<T>::isEmpty() {
    return m_size == 0;
}

template <typename T>
bool MagicChangeBag<T>::isFull() {
    return m_capacity == m_size + 1;
}

template <typename T>
void MagicChangeBag<T>::print() {
    std::cout << "Bag contents: ";
    for (int i = 0; i < m_size; i++) {
        std::cout << m_data[i] << " ";
    }
}

template<typename T>
void MagicChangeBag<T>::resize() {
    T* temp = new T[m_capacity * 2];
    for (int i = 0; i < m_size; i++) {
        temp[i] = m_data[i];
    }
    m_capacity *= 2;
    delete[] m_data;
    m_data = temp;
}

template <typename T>
void MagicChangeBag<T>::removeByIndex(int num) {
    for (int i = num; i < m_size; i++) {
        m_data[i] = m_data[i+1];
    }
    m_size--;
}
template class MagicChangeBag<int>;