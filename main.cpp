#include "bits/stdc++.h"

using namespace std;

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
        Iterator() = default;

        Iterator(const AEVector *pVector, int nIndex) : m_pVector(pVector), Indexiter(nIndex) {}

        Iterator &operator++() {
            ++Indexiter;
            return *this;
        }

        const Iterator operator++(int unused) {
            Iterator temp = *this;
            ++Indexiter;
            return temp;
        }

        Iterator &operator--() {
            --Indexiter;
            return *this;
        }

        const Iterator operator--(int unused) {
            Iterator temp = *this;
            --Indexiter;
            return temp;
        }

        int operator-(const Iterator &other) {
            return Indexiter - other.Indexiter;
        }

        T &operator*() const {
            return m_pVector->operator[](Indexiter);
        }

        bool operator!=(const Iterator &other) {
            return (Indexiter != other.Indexiter);
        }

        bool operator==(const Iterator &other) {
            return Indexiter == other.Indexiter;
        }

        Iterator operator+(int add) {
            return Iterator(m_pVector, Indexiter + add);
        }

        bool operator>(const Iterator &other) {
            return Indexiter > other.m_nIndex;
        }

        bool operator<(const Iterator &other) {
            return Indexiter < other.m_nIndex;
        }


    };
    AEVector(initializer_list<T>NewVec)
    {
        size=cap=NewVec.size();
        arr=new T[size];int i=0;
        for(auto initlist:NewVec){
            arr[i]=initlist;
            i++;
        }
    }

    explicit AEVector(int newsize) {
        size=cap=newsize;
        arr=new T[newsize];
        if(typeid(T)==typeid(int) || typeid(T)==typeid(long long) || typeid(T)==typeid(bool) || typeid(T)==typeid(float )){
            for(int i=0;i<newsize;i++){
                arr[i]=(typeid(T)==typeid(string));
            }
        }
    }
    explicit AEVector() {
        size = cap = 0;
        arr = nullptr;
    }

    AEVector(T *newarr, int n) {
        size = cap = n;
        delete[]arr;
        arr = new T[n];
        for (int i = 0; i < n; i++) {
            arr[i] = newarr[i];
        }
    }

    AEVector(const AEVector &other) {

        size = cap = other.size;
        arr = new T[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    ~AEVector() {
        size = cap = 0;
        delete[]arr;
    }

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

    AEVector(const AEVector &&other) noexcept {
        size = cap = other.size;
        delete[]arr;
        arr = new T[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
        other = 0;
    }

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

    T pop_back() {
        if (size > 0) {
            T Item = arr[size - 1];
            size--;
            return Item;
        }
    }

    void clear() {
        size = 0;
    }

    Iterator begin() {
        return AEVector<T>::Iterator{this, 0};
    }

    Iterator end() {
        return AEVector<T>::Iterator{this, size};
    }

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

    void erase(Iterator iter) {

        AEVector<T>::Iterator j = iter;
        ++j;
        for (AEVector<T>::Iterator i = iter; j != this->end(); ++i, ++j) {
            *i = *j;
        }
        size--;
    }

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
    bool operator==(const AEVector<T> &other) { // Return true if ==
        if (size != other.size) {
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if (arr[i] != other[i])return false;
        }
        return true;
    }

    bool operator<(
            const AEVector<T> &other) {  // Compares item by item  //Return true if first different item in this is < in other

        for (int i = 0; i < min(size, other.Size()); ++i) {
            if (arr[i] != other[i]) {
                return arr[i] < other[i];
            }
        }
        return size < other.Size();

    }

    // Capacity operations
    int Size() const {  // Return current size of vec
        return size;
    }

    int capacity() const { // Return size of current allocated array
        return cap;
    }

    void resize(int newsize) {// Relocate to bigger space
        T newarray = new T[newsize];
        if (newsize > cap) {
            cap = max(2 * cap, newsize);
        }
        for (int i = 0; i < size; ++i) {
            newarray[i] = arr[i];
        }
        for (int i = size; i < newsize; ++i) {
            newarray[i] = 0;
        }
        delete[]arr;
        arr = newarray;
        newarray = nullptr;
        delete[]newarray;
    }

    bool empty() {       // Return true if size is 0
        return !size;
    }

    // Friends
    friend ostream &operator<<(ostream &out, AEVector<T> other) {
        for (int i = 0; i < other.Size(); ++i) {
            cout << other[i] << ' ';
        }
        return out;
    }
};

//----------------------------------------------------------------------------------------------------------------------
int main() {
    AEVector<long long>arr(5);
//    AEVector<int>arr1={53};
//    int i=0;
//    AEVector<int>::Iterator it=arr.begin();
//    arr.insert(it,0);
//    it=arr.end();
//    arr.insert(it,6);
//    arr.erase(it);
    cout<<arr<<endl;
//    if(typeid(arr)==typeid(AEVector<string>)){
//        cout<<"yes"<<endl;
//    }
//    else{
//        cout<<"no"<<endl;
//    }
}


