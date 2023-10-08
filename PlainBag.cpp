#include "PlainBag.h"
#include <iostream>

/**
 * Constructs a new PlainBag
 * @tparam T generic type, currently have set to int.
 */
template <typename T>
PlainBag<T>::PlainBag() {
    m_data = new T[20];
    m_size = 0;
    m_capacity = 20;
}

/**
 * Inserts item into PlainBag
 * @tparam T generic type
 * @param value item to be inserted
 */
template <typename T>
void PlainBag<T>::insert(T value) {
    if (m_capacity == m_size) {
        resize();
    }
    m_data[m_size] = value;
    m_size++;
}
/**
 * removes T value from PlainBag.
 * @tparam T generic Type
 * @param value item to be removed
 * @return return true if successful, false otherwise
 */
template <typename T>
bool PlainBag<T>::remove(T value) {
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
 * @return number of instances of item in PlainBag
 */
template <typename T>
int PlainBag<T>::itemCount(T value) {
    int count = 0;
    for (int i = 0; i < m_size; i++) {
        if(m_data[i] == value)  {
            count++;
        }
    }
    return count;
}
/**
 * Checks PlainBag for any instance of item
 * @tparam T generic type
 * @param value item to be checked
 * @return true if item is found, false otherwise
 */
template <typename T>
bool PlainBag<T>::hasItem(T value) {
    return itemCount(value);
}
/**
 * Gets size of PlainBag
 * @tparam T generic type
 * @return size of PlainBag
 */
template <typename T>
int PlainBag<T>::size() {
    return m_size;
}
/**
 * Empties the PlainBag
 * @tparam T generic type
 */
template <typename T>
void PlainBag<T>::clear() {
    m_size = 0;
}
/**
 * Checks if PlainBag is empty
 * @tparam T generic type
 * @return True if bag is empty, false otherwise.
 */
template <typename T>
bool PlainBag<T>::isEmpty() {
    return m_size == 0;
}
/**
 * Checks if PlainBag is full
 * @tparam T generic type
 * @return true if PlainBag is full, false otherwise
 */
template <typename T>
bool PlainBag<T>::isFull() {
    return m_capacity == m_size + 1;
}
/**
 * Prints out PlainBag contents
 * @tparam T generic type
 */
template <typename T>
void PlainBag<T>::print() {
    std::cout << "Bag contents: ";
    for (int i = 0; i < m_size; i++) {
        std::cout << m_data[i] << " ";
    }
}
/**
* Increases size of PlainBag
* @tparam T generic type
*/
template<typename T>
void PlainBag<T>::resize() {
    T* temp = new T[m_capacity * 2];
    for (int i = 0; i < m_size; i++) {
        temp[i] = m_data[i];
    }
    m_capacity *= 2;
    delete[] m_data;
    m_data = temp;
}
/**
 * Removes the item at given index from PlainBag
 * @tparam T 
 * @param index Index of item to be removed
 */
template <typename T>
void PlainBag<T>::removeByIndex(int num) {
    for (int i = num; i < m_size; i++) {
        m_data[i] = m_data[i+1];
    }
    m_size--;
}
template class PlainBag<int>;//forces compiler to instantiate plainBag of generic type int