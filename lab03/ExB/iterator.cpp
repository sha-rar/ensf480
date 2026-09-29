// iterator.cpp
// ENSF 480 - Fall 2022 - Lab 3, Ex B

#include <iostream>
#include <cassert>
#include <cstring>
#include "mystring2.h"

using namespace std;

template <class T>
class Vector {
public:

  class VectIter {
    friend class Vector<T>;

  private:
    Vector<T> *v;  // points to a vector object of type T
    int index;     // subscript of the current element

  public:
    VectIter(Vector<T>& x);

    T operator++();
    // PROMISES: increments the iterator index and returns the value
    //           at the new index. Wraps to zero after the last element.

    T operator++(int);
    // PROMISES: returns the current value, then increments the iterator
    //           index. Wraps to zero after the last element.

    T operator--();
    // PROMISES: decrements the iterator index and returns the value
    //           at the new index. Wraps to the last element below zero.

    T operator--(int);
    // PROMISES: returns the current value, then decrements the iterator
    //           index. Wraps to the last element below zero.

    T& operator*();
    // PROMISES: returns the value at the current index position.
  };

  Vector(int sz);
  ~Vector();

  T& operator[](int i);
  // PROMISES: returns the ith array element so it can be read or changed.

  void ascending_sort();
  // PROMISES: sorts the vector values in ascending order.

private:
  T *array;
  int size;
  void swap(T&, T&);
};


template <class T>
void Vector<T>::ascending_sort()
{
  for(int i = 0; i < size - 1; i++)
    for(int j = i + 1; j < size; j++)
      if(array[i] > array[j])
        swap(array[i], array[j]);
}


template <class T>
void Vector<T>::swap(T& a, T& b)
{
  T tmp = a;
  a = b;
  b = tmp;
}


template <class T>
T& Vector<T>::VectIter::operator*()
{
  return v->array[index];
}


template <class T>
Vector<T>::VectIter::VectIter(Vector<T>& x)
{
  v = &x;
  index = 0;
}


template <class T>
T Vector<T>::VectIter::operator++()
{
  index++;
  if(index >= v->size)
    index = 0;

  return v->array[index];
}


template <class T>
T Vector<T>::VectIter::operator++(int)
{
  T value = v->array[index];

  index++;
  if(index >= v->size)
    index = 0;

  return value;
}


template <class T>
T Vector<T>::VectIter::operator--()
{
  index--;
  if(index < 0)
    index = v->size - 1;

  return v->array[index];
}


template <class T>
T Vector<T>::VectIter::operator--(int)
{
  T value = v->array[index];

  index--;
  if(index < 0)
    index = v->size - 1;

  return value;
}


template <class T>
Vector<T>::Vector(int sz)
{
  size = sz;
  array = new T[sz];
  assert(array != NULL);
}


template <class T>
Vector<T>::~Vector()
{
  delete [] array;
  array = NULL;
}


template <class T>
T& Vector<T>::operator[](int i)
{
  return array[i];
}


// Specialization required for C-strings. Comparing const char* with > would
// compare pointer addresses rather than the text stored in the strings.
template <>
void Vector<const char*>::ascending_sort()
{
  for(int i = 0; i < size - 1; i++)
    for(int j = i + 1; j < size; j++)
      if(strcmp(array[i], array[j]) > 0)
        swap(array[i], array[j]);
}


int main()
{
  Vector<int> x(3);
  x[0] = 999;
  x[1] = -77;
  x[2] = 88;

  Vector<int>::VectIter iter(x);

  cout << "\n\nThe first element of vector x contains: " << *iter;

  // This section is now included for compilation and testing.
#if 1
  cout << "\nTesting an <int> Vector: " << endl;

  cout << "\n\nTesting sort";
  x.ascending_sort();

  for(int i = 0; i < 3; i++)
    cout << endl << iter++;

  cout << "\n\nTesting Prefix --:";
  for(int i = 0; i < 3; i++)
    cout << endl << --iter;

  cout << "\n\nTesting Prefix ++:";
  for(int i = 0; i < 3; i++)
    cout << endl << ++iter;

  cout << "\n\nTesting Postfix --";
  for(int i = 0; i < 3; i++)
    cout << endl << iter--;

  cout << endl;

  cout << "Testing a <Mystring> Vector: " << endl;
  Vector<Mystring> y(3);
  y[0] = "Bar";
  y[1] = "Foo";
  y[2] = "All";

  Vector<Mystring>::VectIter iters(y);

  cout << "\n\nTesting sort";
  y.ascending_sort();

  for(int i = 0; i < 3; i++)
    cout << endl << iters++;

  cout << "\n\nTesting Prefix --:";
  for(int i = 0; i < 3; i++)
    cout << endl << --iters;

  cout << "\n\nTesting Prefix ++:";
  for(int i = 0; i < 3; i++)
    cout << endl << ++iters;

  cout << "\n\nTesting Postfix --";
  for(int i = 0; i < 3; i++)
    cout << endl << iters--;

  cout << endl;
  cout << "Testing a <char *> Vector: " << endl;
  Vector<const char*> z(3);
  z[0] = "Orange";
  z[1] = "Pear";
  z[2] = "Apple";

  Vector<const char*>::VectIter iterchar(z);

  cout << "\n\nTesting sort";
  z.ascending_sort();

  for(int i = 0; i < 3; i++)
    cout << endl << iterchar++;

#endif

  cout << "\nProgram Terminated Successfully." << endl;

  return 0;
}
