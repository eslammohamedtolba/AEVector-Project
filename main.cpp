#include "bits/stdc++.h"
#include<vector>
using namespace std;
template<class T>
class AEVector{
private:
    int size;
    T *arr;
public:
    AEVector(int newsize=0){
          this->size=size;
          arr=new T[newsize];
          for(int i=0;i<newsize;i++){
              arr[i]=0;
          }
    }
    AEVector(T* newarr,int n){
        size=n;
        arr=new T[n];
        for(int i=0;i<n;i++) {
            arr[i]=newarr[i];
        }
    }
    ~AEVector(){
        delete []arr;
    }
    AEVector(const AEVector &other){
       size=other.size;
       arr=new T[size];
       for(int i=0;i<size;i++){
           arr[i]=other.arr[i];
       }
    }
    AEVector& operator=(const AEVector &other){
        if(this!=&other){
            size=other.size;
            delete []arr;
            arr=new T[size];
            for(int i=0;i<size;i++){
                arr[i]=other.arr[i];
            }
        }
        return*this;
    }
    AEVector(const AEVector &&other){
        size=other.size;
        arr=new T[size];
        for(int i=0;i<size;i++){
            arr[i]=other.arr[i];
        }
        arr= nullptr;
    }
    AEVector&operator=(const AEVector&&other){
        if(this!=&other){
            delete []arr;
            size=other.size;
            arr=new T[size];
            for(int i=0;i<size;i++){
                arr[i]=other.arr[i];
            }
            arr= nullptr;
        }
        return *this;
    }
    T& operator[](int index)
    {
        try {
            if(index<0 || index>=size){
                throw exception();
            }
            else{
                return arr[index];
            }
        }
        catch (exception)
        {
            cout<<"index out of range"<<endl;
        }
    }
    int push_back(T Item){
        size++;
        T *newarr=new T[size];
        for(int i=0;i<size-1;i++){
            newarr[i]=arr[i];
        }
        newarr[size]=Item;
        delete []arr;
        arr=newarr;
        return size;
    }
    T pop_back()
    {
        if(size>0){
            T Item=arr[size-1];
            size--;
            T *newarr=new T[size];
            for(int i=0;i<size;i++){
                newarr[i]=arr[i];
            }
            delete []arr;
            arr=newarr;
            return Item;
        }
    }
//    void erase(iterator<AEVector<T>>::Iter)
//    {
//
//    }
//    void erase(iterator1, iterator2)
//    {
//
//    }
// iterator 1 <= iterator 2 otherwise do nothing
// Throw exception if any iterator outside range
    void clear()
    {
        size=0;
        T newarr=new T[0];
        delete arr;
        arr=newarr;
    }
//    void insert(iterator, T);       // Insert item at iterator
    // Throw exception if invalid

// Iterators 		// Supports *, + and ++ operations at least
// Can use: typedef T* iterator
    // Or u can use std::iterator so you can
// apply STL algorithms on XYVector
//    iterator begin();	// Return an iterator (T*)
//    iterator end()	// Return an iterator (T*)

// Comparison operations
//    bool operator==(const XYVector<T>&) // Return true if ==
//    bool operator< (const XYVector<T>&) // Compares item by item
    // Return true if first different item in this is < in other

// Capacity operations
//    int size() const     // Return current size of vec
//    int capacity() const // Return size of current allocated array
//    int resize()         // Relocate to bigger space
//    bool empty()         // Return true if size is 0

// Friends
//    friend ostream& operator << (ostream& out, XYvector<T>)
};
template <typename T>
class AEvector
{
public:
    typedef typename std::array<T, 3> array_type;
    typedef typename array_type::iterator iterator;
    typedef typename array_type::const_iterator const_iterator;
    inline iterator begin() noexcept { return vec.begin(); }
    inline const_iterator cbegin() const noexcept { return vec.cbegin(); }
    inline iterator end() noexcept { return vec.end(); }
    inline const_iterator cend() const noexcept { return vec.cend(); }
private:
    array_type vec;
};
int main()
{
    AEvector<int>t={1,2,3,4,5,6};
    AEvector<int>::iterator it=t.begin();
    cout<<it<<endl;
}