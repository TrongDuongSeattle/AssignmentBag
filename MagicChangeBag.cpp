#include "MagicChangeBag.h"
#include <iostream>

/**
 * Constructs a new MagicChangeBag
 * @tparam T generic type, currently have set to int.
 */
template <typename T>
MagicChangeBag<T>::MagicChangeBag() {
    m_data = new T[20];
    m_size = 0;
    m_capacity = 20;
}

/**
 * Inserts item into MagicChangeBag
 * @tparam T generic type
 * @param value item to be inserted
 */
template <typename T>
void MagicChangeBag<T>::insert(T value) {
    if (m_capacity == m_size) {
        resize();
    }
    m_data[m_size] = value;
    m_size++;
}
/**
 * removes T value from MagicChangeBag.
 * @tparam T generic Type
 * @param value item to be removed
 * @return return true if successful, false otherwise
 */
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
    return false;
}
/**
 * Counts number of occurrences of given item
 * @tparam T generic type
 * @param value the item to be counted
 * @return number of instances of item in MagicChangeBag
 */
template <typename T>
int MagicChangeBag<T>::itemCount(T value) {
    if (m_size != 20) {
        int count = 0;
        for (int i = 0; i < m_size; i++) {
            if (m_data[i] == value) {
                count++;
            }
        }
        return count;
    }
    return 0;
}
/**
 * Checks MagicChangeBag for any instance of item
 * @tparam T generic type
 * @param value item to be checked
 * @return true if item is found, false otherwise
 */
template <typename T>
bool MagicChangeBag<T>::hasItem(T value) {
    return itemCount(value);
}
/**
 * Gets size of MagicChangeBag, bag will appear empty if full
 * but will show items if an item is removed
 * @tparam T generic type
 * @return 0 is bag is full, otherwise returns number of items in bag
 */
template <typename T>
int MagicChangeBag<T>::size() {
    if (m_size == 20) {
        return 0;
    }
    return m_size;
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
    if(m_size != 20){
        for (int i = 0; i < m_size; i++) {
            std::cout << m_data[i] << " ";
        }
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