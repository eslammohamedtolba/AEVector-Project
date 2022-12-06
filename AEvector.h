#ifndef ASSIGNMENT3_AEVECTOR_H
#define ASSIGNMENT3_AEVECTOR_H
#include <bits/stdc++.h>
using namespace std;
template ………
class XYVector
{
private:
public:
    XYVector (int);
    XYVector (T*, int  n );
    XYVector (const XYVector&);
    ~XYVector();
    XYVector &operator=(const Vector&);
    XYVector &operator=(const Vector&&);
    T& operator[](int);
    int push_back(T);
    T pop_back();
    void erase(iterator);

    void erase(iterator1, iterator2);
    void clear();
    void insert(iterator, T);
    iterator begin();
    iterator end();
    bool operator==(const XYVector<T>&);
    bool operator< (const XYVector<T>&);
    int size() const;
    int capacity() const;
    int resize();
    bool empty();
    friend ostream& operator << (ostream& out, XYvector<T>);
};
#endif //ASSIGNMENT3_AEVECTOR_H
