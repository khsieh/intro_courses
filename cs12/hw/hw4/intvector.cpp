// Course: CS 12 <winter,13>
//
// First Name: Kevin
// Last Name:  Hsieh
// Login id: khsie003
// email address: khsie003@ucr.edu
//
// Lecture Section: 001
// Lab Section: 023
// TA:Mike Izbicki
//
// Assignment: assn4
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ================================================================

#include <iostream>
#include <vector>
#include "intvector.h"


//CONSTRUCTOR AND DESTRUCTOR

/**CONSTRUCTOR :: IntVector::IntVector()
 * The default constructor. 
 * This function should set both the size and capacity to 0 
 * and will not allocate any memory to store integers 
 * (make sure you do not have an uninitialized pointer!)
 */
IntVector::IntVector()
:data(NULL),vcapacity(),vsize()
{
}

/**CONSTRUCTOR :: IntVector::IntVector(unsigned size)
 * 
 * Sets both the size and capacity to the value of the parameter passed in
 * and dynamically allocates an array of that size.
 * All elements must be initialized to 0.
 */  
IntVector::IntVector(unsigned size)
:vcapacity(size),vsize(size)
{
    data = new int[size];
    for(unsigned int i = 0; i < vsize; ++i)
    {
        this -> data[i] = 0;
    }
}

/**CONSTRUCTOR :: IntVector(unsigned size, int value)
 * Sets both the size and capacity to the value of the parameter passed in 
 * and dynamically allocates an array of that size. 
 * This function should initialize all elements of the array to the value of the 2nd parameter.
 */
IntVector::IntVector(unsigned size, int value)
:vcapacity(size),vsize(size)
{
    data = new int[size];
    for(unsigned int i = 0; i < vsize; ++i)
    {
        data[i] = value;
    }
}

/**DESTRUCTOR :: ~IntVector()
 * This function should deallocate all remaining dynamically allocated memory.
 */
IntVector::~IntVector()
{
    delete [] data;
}


//ACCESSORS

/**ACCESSOR :: unsigned size() const
 * This function returns the current size 
 * (not the capacity) of the IntVector object, 
 * which is the value stored in the size data field
 */
unsigned IntVector::size() const
{
    return this -> vsize;
}
/**ACCESSOR :: unsigned capacity() const
 * This function returns the current capacity 
 * (not the size) of the IntVector object, 
 * which is the value stored in the capacity data field.
 */
unsigned IntVector::capacity() const
{
    return this -> vcapacity;
}
/**ACCESSOR :: bool empty() const
 * Returns whether the vector is empty (the size field is 0).
 */
bool IntVector::empty() const
{
    if(vsize == 0)
        return true;
    else
        return false;
}

/**ACCESSOR :: const int& IntVector::at(unsigned int index) const
 * 
 * This function will return the value located at the slot specified by "index": 
 * Note that the return value is "const" 
 * - i.e. it is returned as an "r-value" 
 * Your function should call exit(1) 
 * (i.e. cause the program to terminate cleanly, 
 * with a signal to the Operating System that there was a failure of some sort) 
 * if an index greater than or equal to the size is passed in. 
 * Because the index is an unsigned (rather than just int) 
 * the compiler will not allow for a negative value to be passed in. 
 */ 
const int& IntVector::at(unsigned int index) const
{
    if(index > vsize)
        exit(1);
    return data[index];
}
/**ACCESSOR :: const int & operator[](unsigned index)const
 * This function overloads the subscript operator to return 
 * the value stored at the passed in index position as an r-value, 
 * just like the at function.Unlike the at function, however, 
 * it does NOT check if index is valid or not.
 */
const int& IntVector::operator[](unsigned index)const
{
    return data[index];
}

/**ACCESSOR :: const int & front() const
 * This function will return the element stored at the first index by value 
 * (i.e. as an r-value, just like at and []).
 */
const int& IntVector::front() const
{
    return data[0];
}

/**ACCESSOR :: const int & back() const
 * This function will return the element stored at the last index by value 
 * (i.e. as an r-value, just like at and [])
 */
const int& IntVector::back() const
{
    return data[vsize-1];
}

//MUTATORS
/**MUTATOR :: void insert(unsigned index, int data)
 * This function inserts data at location index. 
    * To do this, all values currently at position index and greater 
    * are shifted to the right by 1 
    * (i.e. each element takes the place of the element right after its current position).
 * size is increased by 1: If size becomes larger than capacity, 
    * this function needs to double the capacity.
 * In other words, if capacity and size are both 20 when this function is called, 
    * capacity will become 40 and size will be set to 21.
 * Since other functions will also potentially need to expand (double) the capacity, 
    * implement the private helper function named expand (see above) to do this for you. 
    * This function should call exit(1) if an index value greater than size is passed in.
 */
void IntVector::insert(unsigned index, int data)
{
    if(index > vsize)
        exit(1);
    if(vsize >= vcapacity)
        expand();
    if(vsize == 0 && vcapacity == 0)
        expand(1);
        
    for(unsigned int i = vsize; i > index; --i)
    {
        this -> data[i] = this -> data[i-1];
    }
    this -> data[index] = data;
    vsize++;
}

/**MUTATOR :: void erase(unsigned index)
 * This function removes the value at position index 
    * and shifts all of the values at positions greater than index to the left by one 
    * (to the element right before its current position).
 * Size is decreased by 1. This function should call exit(1) 
    * if an index value greater than or equal to size is passed in.
 */
void IntVector::erase(unsigned index)
{
    if(index >= vsize)
        exit(1);
    
    for(unsigned int i = index; i < vsize - 1; ++i)
    {
        this -> data[i] = this -> data[i+1];
    }
    vsize--;
} 

/**MUTATOR :: void push_back(int data)
 * This function inserts a value at the back end of the array.
 * Size is increased by 1: If size becomes larger than capacity, 
    * this function needs to double the capacity.
 * In other words, if capacity and size are both 20 when this function is called, 
    * capacity will become 40 and size will be set to 21.
 * Special case: If the capacity is 0, 
    * expand the vector so that it has allocated space of length 1 
    * and set vcapacity to 1. (You can use expand(int))
 */
void IntVector::push_back(int data)
{
    if(vcapacity == 0)
        expand(1);
    else if(vsize == vcapacity)
        expand();
    
    this -> data[vsize] = data;
    vsize++;
}

/**MUTATOR :: void pop_back()
 * This function just needs to decrease size by 1.
 * This function should call exit(1) if pop_back is called on an empty vector.
 */
void IntVector::pop_back()
{
    if(this->vsize == 0 || this-> vcapacity == 0)
        exit(1);
    this -> vsize -=1;
    
}

/**MUTATOR :: void clear()
 * This function reduces the size of the vector to 0.
 */
void IntVector::clear()
{
    vsize = 0;
}

/**MUTATOR :: void resize(unsigned sz)
 * This function resizes the vector to contain sz elements.
 * If sz < vsize,this function just reduces the value of size to sz.
 * If sz > vsize, then the appropriate number of elements are inserted at the end of the vector, 
    * giving all of the new elements a value of 0.
 * If sz > vcapacity, then the capacity should be expanded by 
    * either doubling (expand()) or by increasing the capacity 
    * by a specific amount (expand( sz - capacity )),
    * whichever results in the largest capacity.
 */
void IntVector::resize(unsigned sz)
{
    if(sz < vsize)
        vsize = sz;
    else if(sz > vsize && sz < vcapacity)
    {
        vsize = sz;
        for(unsigned int i = vsize + 1; i <= vcapacity;++i)
            this -> data[i] = 0;
     }
     else if (sz > vcapacity)
    {
        if( (vcapacity*2) > (sz + vcapacity))
            expand();
        else if( (sz + vcapacity) > (vcapacity*2) )
            expand(sz - vcapacity);
            
        for(unsigned int i = vsize + 1; i <= vcapacity;++i)
            this -> data[i] = 0;
    }
}

/**MUTATOR :: void resize(unsigned sz, int value)
 * This function resizes the vector to containt sz elements.
 * If sz < vsize, this function just reduces the value of size to sz.
 * If sz > vsize, then the appropriate number of elements are inserted at the end of the vector, 
    * giving all of the new elements the value passed in through (value).
 * If sz > vcapacity, then the capacity should be expanded by either (expand()) 
    * or by increasing the capacity by a specific amount (expand( sz - capacity )), 
    * whichever results in the largest capacity.*/
void IntVector::resize(unsigned sz, int value)
{
    if(sz < vsize)
        vsize = sz;
    else if(sz > vsize && sz < vcapacity)
    {
        for(unsigned int i = vsize; i <= vcapacity;++i)
            this -> data[i] = value;
        vsize = sz;
     }
     else if (sz > vcapacity)
    {
        if( (vcapacity*2) > (sz))
            expand();
        else if( (sz) > (vcapacity*2) )
            expand(sz - vcapacity); 
        
        for(unsigned int i = vsize; i <= vcapacity;++i)
            this -> data[i] = value;
        vsize = sz;
    }
}

/**MUTATOR :: void reserve(unsigned n)
 * This function requests that the capacity (the size of the dynamically allocated array) 
    * be set to n at minimum. This informs the vector of a planned increase in size, 
    * although notice that the parameter n informs of a minimum, 
    * so the resulting capacity may be any capacity equal or larger than this.
 * This function should NOT ever reduce the size of the vector. 
    * If n is larger than the current capacity then the capacity should be expanded 
    * by either (expand()) or by increasing the capacity by (expand( n - capacity )), 
    * whichever results in the largest capacity.
 * In any case, a call to this function never affects the elements contained in the vector, 
    * nor the vector size.
 */
void IntVector::reserve(unsigned n)
{
    if(n > vcapacity)
    {
        if( (n) > (vcapacity * 2) )
            expand(n - vcapacity);
        else if( (n) < (vcapacity * 2) )
            expand();
    }
}

/**MUTATOR :: void assign(unsigned n, int value)
 * Assigns new content to the vector object, 
    * dropping all the elements contained in the vector before the call and 
    * replacing them by those specified by the parameters. 
    * The new value of size will be n and all values stored in the vector will be (int value).
 * If the new value of size will be larger than capacity, 
    * then the capacity should be expanded by either (expand()) or 
    * by increasing the capacity by expand( size - capacity )), 
    * whichever results in the largest capacity.
 */
void IntVector::assign(unsigned n, int value)
{
    if(n <= vcapacity)
    {
        for(unsigned int i = 0; i <= n; ++i)
            this -> data[i] = value;
        vsize = n;
    }
    else if(n > vcapacity)
    {
        if( (n) > (vcapacity * 2) )
            expand(n-vcapacity);
        else if( (n) < (vcapacity * 2) )
            expand();
            
        for(unsigned int i = 0; i <= n; ++i)
            this -> data[i] = value;
            
        vsize = n;
    }
}

/**MUTATOR :: int& IntVector::at(unsigned int index)
 * 
 * This function will return a reference to the value 
 * stored at the element at the passed in index position. 
 * Unlike the equivalent accessor function, 
 * this is an "l-value". 
 * Your function should call exit(1) 
 * (i.e. cause the program to terminate cleanly, 
 * with a signal to the Operating System that there was a failure of some sort) 
 * if an index greater than or equal to the size is passed in. 
 * Because the index is an unsigned (rather than just int) 
 * the compiler will not allow for a negative value to be passed in.
 */ 
int& IntVector::at(unsigned int index)
{
    if(index > vsize)
        exit(1);
    return data[index];
}

/**MUTATOR :: int & operator[](unsigned index)
 * This function overloads the subscript operator and returns 
 * a reference to the value stored at the passed in index position 
 * (i.e. an l-value). Unlike at function, it does NOT check if index is valid or not.
 */
int& IntVector::operator [](unsigned index)
{
    return data[index];
}

/**MUTATOR :: int & front()
 * This function will return the element stored at the first index by reference 
 * (i.e. as an l-value
 */
int& IntVector::front()
{
    return data[0];
} 

/**MUTATOR :: int & back()
 * This function will return the element stored at the last index by reference 
 * (i.e. as an l-value).
 */
int& IntVector::back()
{
    return data[vsize-1];
}


//PRIVATE MEMBER FUNCTIONS

/**void expand()
 * This function will double the capacity of the vector. 
 * This function should reallocate memory for the dynamically allocated array 
 * and update the value of capacity. 
 * Make sure you don't create a memory leak here.
 */
void IntVector::expand()
{
    int* temp_array = data;
    vcapacity *= 2;
    data = new int[vcapacity];
    
    for(unsigned int x = 0; x < (vcapacity/2); ++x )
    {
        data[x] = temp_array[x];
    }
    delete [] temp_array;
}

/**void expand(unsigned amount)
 * This function will expand the capacity of the vector by amount passed in. 
 * This function should reallocate memory for the dynamically allocated array
 * and update the value of capacity. 
 * Make sure you don't create a memory leak here.
 */
void IntVector::expand(unsigned amount)
{
    int* temp_array = data;
    vcapacity += amount;
    data = new int[vcapacity];
    
    for(unsigned int x = 0; x < (vcapacity - amount); ++x )
    {
        data[x] = temp_array[x];
    }
    delete [] temp_array;
}

