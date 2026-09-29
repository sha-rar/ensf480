// mystring2.cpp
// ENSF 480 - Lab 3
// M. Moussavi

#include "mystring2.h"
#include <string.h>
#include <iostream>

using namespace std;

Mystring::Mystring()
{
  charsM = new char[1];
  charsM[0] = '\0';
  lengthM = 0;
}

Mystring::Mystring(const char *s)
  : lengthM((int)strlen(s))
{
  charsM = new char[lengthM + 1];
  strcpy(charsM, s);
}

Mystring::Mystring(int n)
  : lengthM(0), charsM(new char[n])
{
  charsM[0] = '\0';
}

Mystring::Mystring(const Mystring& source)
  : lengthM(source.lengthM), charsM(new char[source.lengthM + 1])
{
  strcpy(charsM, source.charsM);
}

Mystring::~Mystring()
{
  delete [] charsM;
}

int Mystring::length() const
{
  return lengthM;
}

char Mystring::get_char(int pos) const
{
  if(pos < 0 || pos >= length()) {
    cerr << "\nERROR: get_char: the position is out of boundary.";
  }

  return charsM[pos];
}

const char * Mystring::c_str() const
{
  return charsM;
}

void Mystring::set_char(int pos, char c)
{
  if(pos < 0 || pos >= length()) {
    cerr << "\nset_char: the position is out of boundary."
         << " Nothing was changed.";
    return;
  }

  if(c == '\0') {
    cerr << "\nset_char: char c is empty."
         << " Nothing was changed.";
    return;
  }

  charsM[pos] = c;
}

Mystring& Mystring::operator =(const Mystring& S)
{
  if(this == &S)
    return *this;

  delete [] charsM;
  lengthM = (int)strlen(S.charsM);
  charsM = new char[lengthM + 1];
  strcpy(charsM, S.charsM);
  return *this;
}

bool Mystring::operator >(const Mystring& rhs) const
{
  return strcmp(charsM, rhs.charsM) > 0;
}

Mystring& Mystring::append(const Mystring& other)
{
  char *tmp = new char[lengthM + other.lengthM + 1];
  strcpy(tmp, charsM);
  strcat(tmp, other.charsM);

  lengthM += other.lengthM;
  delete [] charsM;
  charsM = tmp;

  return *this;
}

void Mystring::set_str(char* s)
{
  delete [] charsM;
  lengthM = (int)strlen(s);
  charsM = new char[lengthM + 1];
  strcpy(charsM, s);
}

std::ostream& operator <<(std::ostream& os, const Mystring& s)
{
  return os << s.charsM;
}
