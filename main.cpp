#include "bits/stdc++.h"
using namespace std;
template<class T>
class AEVector{
private:
    int size;
    T *arr;
public:
    class Iterator
    {
    public:
        Iterator();
        Iterator(const AEVector *pVector, int nIndex): m_pVector(pVector), Indexiter(nIndex){}
        Iterator &operator++()
        {
                ++Indexiter;
                return *this;
        }
        const T &operator*() const
        {
            return m_pVector->operator[](Indexiter);
        }
        bool operator!=(const Iterator &other)
        {
            return (Indexiter != other.Indexiter);
        }
        bool operator==(const Iterator &other)
        {
            return Indexiter == other.m_nIndex;
        }
    private:
        const AEVector *m_pVector;
        int Indexiter = -1;
    };
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
        size=0;
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
    const T& operator[](int index) const
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
    void clear()
    {
        size=0;
        arr= nullptr;
    }
    //---------------------------------------------------------------
    Iterator begin()
    {
        return AEVector<T>::Iterator{this,0};
    }
    Iterator end()
    {
        return AEVector<T>::Iterator{this,size};
    }
    void insert(Iterator iter,T value)
    {
        size++;
        T *newarr=new T[size];int index=0;
        cout<<*this->begin()<<endl;
        for(AEVector<T>::Iterator i=Iterator{this,0};i!=Iterator{this,0};++i){
            if(i!=iter){
                newarr[index]=*i;
            }
            else{
                newarr[index]=value;index++;
            }
            index++;
        }
        delete arr;
        arr=newarr;
    }
    void erase(Iterator iter)
    {
        size--;
        T *newarr=new T[size];int index=0;
        for(AEVector<T>::Iterator i=this->begin();i!=this->end();++i){
            if(i!=iter){
                newarr[index]=*i;
                index++;
            }
        }
        delete arr;
        arr=newarr;
    }
    void erase(Iterator iter1, Iterator iter2);     // Remove items between
                                                    // iterator 1 <= iterator 2 otherwise do nothing
                                                    // Throw exception if any iterator outside range

    // Iterators 		// Supports *, + and ++ operations at least
                        // Can use: typedef T* iterator
                        // Or u can use std::iterator so you can
                        // apply STL algorithms on XYVector

    // Comparison operations
    bool operator==(const AEVector<T>&); // Return true if ==
    bool operator< (const AEVector<T>&); // Compares item by item
                                         //Return true if first different item in this is < in other

    // Capacity operations
    int Size() const;     // Return current size of vec
    int capacity() const; // Return size of current allocated array
    int resize();         // Relocate to bigger space
    bool empty();         // Return true if size is 0

    // Friends
    friend ostream& operator << (ostream& out, AEVector<T>other);
};
//----------------------------------------------------------------------------------------------------------------------
int main()
{
    AEVector<int>t;
    AEVector<int>::Iterator it=t.begin();
    t.insert(it,5);
    t.erase(it);
    cout<<"Eslam"<<endl;
}