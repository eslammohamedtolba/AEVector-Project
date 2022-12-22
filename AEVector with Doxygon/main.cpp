/**
 * @file main.cpp
 * @author _1 Eslam Mohamed Abdulazim Ali Tolba (eslam3012tolba@gmail.com)
 * @author _2 Abdelrahman wael (abdelrahmanweal5@gmail.com)
 * @brief  this is the main
 * @details this file is a structure of the vector representation functions that make it as the same as original vector
 * @version 0.5
 * @date 2022-12-10
 */
#include "bits/stdc++.h"
using namespace std;
/**
 * @brief this class to represent a class of the vector representation
 * @tparam T the template parameter that represents the type of the vector 
 */
template<class T>
class AEVector {
private:
    int size;
    int cap;
    T *arr;
public:
    class Iterator {
        const AEVector *m_pVector{};
        int Indexiter = -1;
    public:
        /**
         * @brief Construct a new Iterator object
         */
        Iterator() = default;
        /**
         * @brief Construct a new Iterator object
         * @param pVector the vector that we take copy from it
         * @param nIndex the size of the vector that we take copy from it
         */
        Iterator(const AEVector *pVector, int nIndex) : m_pVector(pVector), Indexiter(nIndex) {}
        /**
         * @brief operator that make us able to increment iterator of the vector from the beginning
         * @return Iterator& 
         */
        Iterator &operator++() {
            ++Indexiter;
            return *this;
        }
        /**
         * @brief operator that make us able to increment iterator of the vector
         * @param unused initial value
         * @return const Iterator 
         */
        const Iterator operator++(int unused) {
            Iterator temp = *this;
            ++Indexiter;
            return temp;
        }
        /**
         * @brief operator that make us able to decrement iterator of the vector from the beginning
         * @return Iterator& 
         */
        Iterator &operator--() {
            --Indexiter;
            return *this;
        }
        /**
         * @brief operator that make us able to decrement iterator of the vector
         * @return Iterator& 
         */
        const Iterator operator--(int unused) {
            Iterator temp = *this;
            --Indexiter;
            return temp;
        }
        int operator-(const Iterator &other) {
            return Indexiter - other.Indexiter;
        }
        /**
         * @brief to find the value in that position iterator 
         * @return T& 
         */
        T &operator*() const {
            return m_pVector->operator[](Indexiter);
        }
        /**
         * @brief to check if the current iterator is not the other iterator
         * @param other the another iterator to compare against the current iterator 
         * @return true 
         * @return false 
         */
        bool operator!=(const Iterator &other) {
            return (Indexiter != other.Indexiter);
        }
        /**
         * @brief to check if the current iterator is the other iterator
         * @param other the another iterator to compare against the current iterator 
         * @return true 
         * @return false 
         */
        bool operator==(const Iterator &other) {
            return Indexiter == other.Indexiter;
        }
        Iterator operator+(int add) {
            return Iterator(m_pVector, Indexiter + add);
        }
        /**
         * @brief to check if the current iterator is greater than the other iterator
         * @param other the another iterator to compare against the current iterator 
         * @return true 
         * @return false 
         */
        bool operator>(const Iterator &other) {
            return Indexiter > other.m_nIndex;
        }
        /**
         * @brief to check if the current iterator is samller than the other iterator
         * @param other the another iterator to compare against the current iterator 
         * @return true 
         * @return false 
         */
        bool operator<(const Iterator &other) {
            return Indexiter < other.m_nIndex;
        }


    };
    /**
     * @brief Construct a new AEVector object
     * @param NewVec another initializer list to put its values to the current vector
     */
    AEVector(initializer_list<T> NewVec) {
        size = cap = NewVec.size();
        arr = new T[size];
        int i = 0;
        for (auto initlist: NewVec) {
            arr[i] = initlist;
            i++;
        }
    }
    /**
     * @brief Construct a new AEVector object
     * @param newsize to take new size to construct vector of this size
     */
    explicit AEVector(int newsize) {
        size = cap = newsize;
        arr = new T[newsize];
        if (typeid(T) != typeid(string)) {
            for (int i = 0; i < newsize; i++) {
                arr[i] = (typeid(T) == typeid(string));
            }
        }
    }
    /**
     * @brief Construct a new AEVector object
     * @param newsize the size that will costruct the vector by 
     * @param value the value that will be put in all positions as a initial value
     */
    explicit AEVector(int newsize, T value) {
        size = cap = newsize;
        arr = new T[newsize];
        for (int i = 0; i < newsize; i++) {
            arr[i] = value;
        }
    }
    /**
     * @brief Construct a new AEVector object 
     */
    explicit AEVector() {
        size = cap = 0;
        arr = nullptr;
    }
    /**
     * @brief Construct a new AEVector object
     * @param newarr the array that its values will be transferred to the vector
     * @param n the size of the array 
     */
    AEVector(T *newarr, int n) {
        size = cap = n;
        delete[]arr;
        arr = new T[n];
        for (int i = 0; i < n; i++) {
            arr[i] = newarr[i];
        }
    }
    /**
     * @brief Construct a new AEVector object
     * @param other another vector taken to transferred its values to the current vector
     */
    AEVector(const AEVector &other) {

        size = cap = other.size;
        arr = new T[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }
    /**
     * @brief Destroy the AEVector object
     */
    ~AEVector() {
        size = cap = 0;
        delete[]arr;
    }
    /**
     * @brief this operator created to equal two vectors by the other vector values
     * @param other the another vector 
     * @return AEVector& 
     */
    AEVector &operator=(const AEVector &other) {
        if (this != &other) {
            size = cap = other.size;
            delete[]arr;
            arr = new T[size];
            for (int i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }
    /**
     * @brief Construct a new AEVector object
     * @param other another vector to copy its values to current vector
     */
    AEVector(const AEVector &&other) noexcept {
        size = cap = other.size;
        delete[]arr;
        arr = new T[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
        other = 0;
    }
    /**
     * @brief assignment operator 
     * @param other another vector 
     * @return AEVector& 
     */
    AEVector &operator=(const AEVector &&other) noexcept {
        if (this != &other) {
            delete[]arr;
            size = cap = other.size;
            arr = new T[size];
            for (int i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }

        }
        other = 0;
        return *this;
    }
    /**
     * @brief return vector value that has this index
     * @param index index that will return its value
     * @return T& 
     */
    T &operator[](int index) const {
        try {
            if (index < 0 || index >= size) {
                throw exception();
            } else {
                return arr[index];
            }
        }
        catch (exception) {
            cout << "index out of range" << endl;
        }
    }
    /**
     * @brief push_back function
     * @param Item the value that will put in the vector end
     * @return int 
     */
    int push_back(T Item) {
        if (size == cap) {
            cap = cap * 2;
            T *newarr = new T[cap];
            for (int i = 0; i < size; i++) {
                newarr[i] = arr[i];
            }
            delete[]arr;
            arr = newarr;
        }
        arr[size] = Item;
        size++;
        return size;
    }
    /**
     * @brief pop_back function that remove the last value from vector
     * @return T 
     */
    T pop_back() {
        if (size > 0) {
            T Item = arr[size - 1];
            size--;
            return Item;
        }
    }
    /**
     * @brief vector clear that remove all vector values
     */
    void clear() {
        size = 0;
    }
    /**
     * @brief vector begin that return pointer for the first vector value 
     * @return Iterator 
     */
    Iterator begin() {
        return AEVector<T>::Iterator{this, 0};
    }
    /**
     * @brief vector begin that return pointer for after from the last vector value 
     * @return Iterator 
     */
    Iterator end() {
        return AEVector<T>::Iterator{this, size};
    }
    /**
     * @brief insert vlaue in the vector
     * @param iter iterator points to the index that will be insert in it
     * @param value the value that will be inserted
     */
    void insert(Iterator iter, T value) {
        if (size == cap)cap *= 2;
        ++size;
        T *newarr = new T[cap];
        int index = 0;
        for (AEVector<T>::Iterator i = this->begin(); i != iter; ++i) {
            newarr[index] = arr[index];
            ++index;
        }
        newarr[index] = value;
        ++index;
        for (int i = index - 1; index < size; ++i, ++index) {
            newarr[index] = arr[i];
        }
        arr = newarr;
        newarr = nullptr;
        delete[]newarr;
    }
    /**
     * @brief erase function that erase the value from the vector
     * @param iter iterator points to the index that will be erase in it
     */
    void erase(Iterator iter) {

        AEVector<T>::Iterator j = iter;
        ++j;
        for (AEVector<T>::Iterator i = iter; j != this->end(); ++i, ++j) {
            *i = *j;
        }
        size--;
    }
    /**
     * @brief erase function that erase period of values from the vector
     * @param iter1 the first iterator that points to the start index of the period
     * @param iter2 the second iterator that points to the end index of the period
     */
    void erase(Iterator iter1, Iterator iter2) {

        AEVector<T>::Iterator i = iter1, j = iter2;
        for (; j != Iterator(this, size); ++i, ++j) {
            *i = *j;
        }

        size -= iter2 - iter1;
    }

    // Remove items between
    // iterator 1 <= iterator 2 otherwise do nothing
    // Throw exception if any iterator outside range

    // Iterators 		// Supports *, + and ++ operations at least
    // Can use: typedef T* iterator
    // Or u can use std::iterator so you can
    // apply STL algorithms on XYVector

    // Comparison operations

    /**
     * @brief operator equal to check equality of two vectors 
     * @param other the another vector of the operator
     * @return true 
     * @return false 
     */
    bool operator==(const AEVector<T> &other) { // Return true if ==
        if (size != other.size) {
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if (arr[i] != other[i])return false;
        }
        return true;
    }

    /**
     * @brief operator smaller than 
     * @param other the another vector of the operator
     * @return true 
     * @return false 
     */
    bool operator<(
            const AEVector<T> &other) {  // Compares item by item  //Return true if first different item in this is < in other

        for (int i = 0; i < min(size, other.Size()); ++i) {
            if (arr[i] != other[i]) {
                return arr[i] < other[i];
            }
        }
        return size < other.Size();

    }

    /**
     * @brief the size of the vector
     * @return int 
     */
    int Size() const { 
        return size;
    }
    /**
     * @brief the capacity of the vector
     * @return int 
     */
    int capacity() const { 
        return cap;
    }
    /**
     * @brief the function resize that resize the capacity and size of the vector
     * @param newsize the new size that will be vector size
     */
    void resize(int newsize) {// Relocate to bigger space
        if (newsize > cap) {
            cap = max(2 * cap, newsize);
        }

        T *newarray = new T[cap];
        for (int i = 0; i < size; ++i) {
            newarray[i] = arr[i];
        }
        if (typeid(T) != typeid(string)) {
            for (int i = size; i < newsize; i++) {
                newarray[i] = (typeid(T) == typeid(string));
            }
        }
        size = newsize;

        delete[]arr;
        arr = newarray;
        newarray = nullptr;
        delete[]newarray;
    }

    void resize(int newsize, T value) {// Relocate to bigger space
        if (newsize > cap) {
            cap = max(2 * cap, newsize);
        }

        T *newarray = new T[cap];
        for (int i = 0; i < size; ++i) {
            newarray[i] = arr[i];
        }
        for (int i = size; i < newsize; i++) {
            newarray[i] = value;
        }

        size = newsize;

        delete[]arr;
        arr = newarray;
        newarray = nullptr;
        delete[]newarray;
    }
    /**
     * @brief the empty function that checks if the vector is empty
     * @return true 
     * @return false 
     */
    bool empty() {       // Return true if size is 0
        return !size;
    }

    /**
     * @brief cout function for vector
     * @param out the ostream opterator output
     * @param other the vector that will be printed
     * @return ostream& 
     */
    friend ostream &operator<<(ostream &out, AEVector<T> other) {
        for (int i = 0; i < other.Size(); ++i) {
            cout << other[i] << ' ';
        }
        return out;
    }
};

//----------------------------------------------------------------------------------------------------------------------
int main() {

    AEVector<string> arr(10, "abdo");
    arr.push_back("10");
    arr.resize(20, "50");
    cout << arr.capacity() << endl;

    cout << arr << endl;
}


