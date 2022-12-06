#include <bits/stdc++.h>
using namespace std;
//----------------------------------------------------------------------------------------------------------------------
template ………
class XYVector
{
private:
public:
    // Constructors and Big 4
    XYVector (int)			// Initialize by specific capacity
                            // No content is added, size = 0
                            // Assign a default size value
    XYVector (T*, int  n )		// Initialize by n items from array
    XYVector (const XYVector&)	// Initialize with a copy
    ~XYVector()				// Delete allocated memory
    XYVector &operator=(const Vector&);  // Copy assignment
    XYVector &operator=(const Vector&&); // Move assignment

    // Access operations
    T& operator[](int) // Access item by reference
    // Throw an exception if out of range

    // Modifying operations
    int push_back(T)    // Add item to end of vec & return # of items
                        // Increase capacity of needed

    T pop_back()        // Remove and return last element in vec
    void erase(iterator)    // Remove item at iterator
						    // Throw exception if invalid iter

    void erase(iterator1, iterator2)// Remove items between
                                    // iterator 1 <= iterator 2 otherwise do nothing
                                    // Throw exception if any iterator outside range

    void clear()     // Delete all vector content
    void insert(iterator, T)       // Insert item at iterator
                                    // Throw exception if invalid

    // Iterators 		// Supports *, + and ++ operations at least
                        // Can use: typedef T* iterator
                        // Or u can use std::iterator so you can
                        // apply STL algorithms on XYVector
    iterator begin()	// Return an iterator (T*)
    iterator end()	// Return an iterator (T*)

    // Comparison operations
    bool operator==(const XYVector<T>&) // Return true if ==
    bool operator< (const XYVector<T>&) // Compares item by item
	                                    // Return true if first different item in this is < in other

    // Capacity operations
    int size() const     // Return current size of vec
    int capacity() const // Return size of current allocated array
    int resize()         // Relocate to bigger space
    bool empty()         // Return true if size is 0

    // Friends
    friend ostream& operator << (ostream& out, XYvector<T>)
};
//----------------------------------------------------------------------------------------------------------------------
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
