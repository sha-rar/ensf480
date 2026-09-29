//File: mystring2.h
// ENSF 480 - Lab 3

#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class Mystring {
  friend std::ostream& operator <<(std::ostream& os, const Mystring& s);

public:
  Mystring();
  // PROMISES: Empty string object is created.

  Mystring(int n);
  // PROMISES: Creates an empty string with a total capacity of n.
  //           In other words, dynamically allocates n elements for
  //           charsM, sets lengthM to zero, and fills the first
  //           element of charsM with '\0'.

  Mystring(const char *s);
  // REQUIRES: s points to first char of a built-in string.
  // PROMISES: Mystring object is created by copying chars from s.

  ~Mystring();

  Mystring(const Mystring& source);

  Mystring& operator =(const Mystring& rhs);
  // REQUIRES: rhs is reference to a Mystring as a source.
  // PROMISES: Makes this object a copy of rhs.

  bool operator >(const Mystring& rhs) const;
  // PROMISES: Returns true if this string comes after rhs
  //           lexicographically.

  int length() const;
  // PROMISES: Return value is number of chars in charsM.

  char get_char(int pos) const;
  // REQUIRES: pos >= 0 && pos < length()
  // PROMISES: Return value is char at position pos.

  const char * c_str() const;
  // PROMISES: Return value points to first char in built-in string
  //           containing the chars of the string object.

  void set_char(int pos, char c);
  // REQUIRES: pos >= 0 && pos < length(), c != '\0'
  // PROMISES: Character at position pos is set equal to c.

  Mystring& append(const Mystring& other);
  // PROMISES: Concatenates other to the end of this string.

  void set_str(char* s);
  // REQUIRES: s is a valid C++ string of characters (a built-in string).
  // PROMISES: Copies s into charsM.

private:
  int lengthM;
  char* charsM;
  void memory_check(char* s);
};

#endif
