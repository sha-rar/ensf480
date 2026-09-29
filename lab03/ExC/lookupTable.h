// LookupTable.h
// ENSF 480 - Lab 3, Ex C

#ifndef LOOKUPTABLE_H
#define LOOKUPTABLE_H

#include <assert.h>
#include <cstring>
#include <iostream>
#include "customer.h"

using namespace std;

// Generic key comparison helpers.
// The general versions use the key type's relational operators.
template <class Key>
bool key_less(const Key& a, const Key& b)
{
  return a < b;
}

template <class Key>
bool key_equal(const Key& a, const Key& b)
{
  return a == b;
}

// C-string keys must be compared by their contents, not pointer addresses.
inline bool key_less(const char* const& a, const char* const& b)
{
  return strcmp(a, b) < 0;
}

inline bool key_equal(const char* const& a, const char* const& b)
{
  return strcmp(a, b) == 0;
}

// Mystring does not define all relational operators, so compare its C strings.
inline bool key_less(const Mystring& a, const Mystring& b)
{
  return strcmp(a.c_str(), b.c_str()) < 0;
}

inline bool key_equal(const Mystring& a, const Mystring& b)
{
  return strcmp(a.c_str(), b.c_str()) == 0;
}

// A generic key/datum pair.
template <class Key, class Datum>
struct Pair
{
  Pair(const Key& keyA, const Datum& datumA)
    : key(keyA), datum(datumA)
  {
  }

  Key key;
  Datum datum;
};

template <class Key, class Datum>
class LookupTable;

// A node used internally by LookupTable.
template <class Key, class Datum>
class LT_Node
{
  friend class LookupTable<Key, Datum>;

private:
  Pair<Key, Datum> pairM;
  LT_Node<Key, Datum>* nextM;

  LT_Node(const Pair<Key, Datum>& pairA, LT_Node<Key, Datum>* nextA)
    : pairM(pairA), nextM(nextA)
  {
  }
};

template <class Key, class Datum>
class LookupTable
{
public:
  class Iterator
  {
    friend class LookupTable<Key, Datum>;

  private:
    LookupTable<Key, Datum>* LT;

  public:
    Iterator() : LT(0) {}
    Iterator(LookupTable<Key, Datum>& x) : LT(&x) {}

    const Datum& operator*()
    {
      assert(LT != 0 && LT->cursor_ok());
      return LT->cursor_datum();
    }

    // These retain the behaviour expected by the supplied test loop:
    // return the current datum, then advance the table cursor.
    const Datum& operator++()
    {
      assert(LT != 0 && LT->cursor_ok());
      const Datum& x = LT->cursor_datum();
      LT->step_fwd();
      return x;
    }

    const Datum& operator++(int)
    {
      assert(LT != 0 && LT->cursor_ok());
      const Datum& x = LT->cursor_datum();
      LT->step_fwd();
      return x;
    }

    int operator!()
    {
      return LT != 0 && LT->cursor_ok();
    }

    void step_fwd()
    {
      assert(LT != 0 && LT->cursor_ok());
      LT->step_fwd();
    }
  };

  LookupTable()
    : sizeM(0), headM(0), cursorM(0)
  {
  }

  LookupTable(const LookupTable<Key, Datum>& source)
    : sizeM(0), headM(0), cursorM(0)
  {
    copy(source);
  }

  LookupTable<Key, Datum>& operator=(const LookupTable<Key, Datum>& rhs)
  {
    if (this != &rhs) {
      destroy();
      copy(rhs);
    }
    return *this;
  }

  ~LookupTable()
  {
    destroy();
  }

  LookupTable<Key, Datum>& begin()
  {
    cursorM = headM;
    return *this;
  }

  int size() const
  {
    return sizeM;
  }

  int cursor_ok() const
  {
    return cursorM != 0;
  }

  const Key& cursor_key() const
  {
    assert(cursor_ok());
    return cursorM->pairM.key;
  }

  const Datum& cursor_datum() const
  {
    assert(cursor_ok());
    return cursorM->pairM.datum;
  }

  void insert(const Pair<Key, Datum>& pairA)
  {
    // Add a new node at the head.
    if (headM == 0 || key_less(pairA.key, headM->pairM.key)) {
      headM = new LT_Node<Key, Datum>(pairA, headM);
      sizeM++;
    }
    // Overwrite the datum at the head.
    else if (key_equal(pairA.key, headM->pairM.key)) {
      headM->pairM.datum = pairA.datum;
    }
    else {
      LT_Node<Key, Datum>* before = headM;
      LT_Node<Key, Datum>* after = headM->nextM;

      while (after != 0 && key_less(after->pairM.key, pairA.key)) {
        before = after;
        after = after->nextM;
      }

      if (after != 0 && key_equal(pairA.key, after->pairM.key)) {
        after->pairM.datum = pairA.datum;
      }
      else {
        before->nextM = new LT_Node<Key, Datum>(pairA, after);
        sizeM++;
      }
    }

    cursorM = 0;
  }

  void remove(const Key& keyA)
  {
    if (headM == 0 || key_less(keyA, headM->pairM.key)) {
      cursorM = 0;
      return;
    }

    LT_Node<Key, Datum>* doomed_node = 0;

    if (key_equal(keyA, headM->pairM.key)) {
      doomed_node = headM;
      headM = headM->nextM;
      sizeM--;
    }
    else {
      LT_Node<Key, Datum>* before = headM;
      LT_Node<Key, Datum>* maybe_doomed = headM->nextM;

      while (maybe_doomed != 0 && key_less(maybe_doomed->pairM.key, keyA)) {
        before = maybe_doomed;
        maybe_doomed = maybe_doomed->nextM;
      }

      if (maybe_doomed != 0 && key_equal(maybe_doomed->pairM.key, keyA)) {
        doomed_node = maybe_doomed;
        before->nextM = maybe_doomed->nextM;
        sizeM--;
      }
    }

    delete doomed_node;
    cursorM = 0;
  }

  void find(const Key& keyA)
  {
    LT_Node<Key, Datum>* ptr = headM;

    while (ptr != 0 && !key_equal(ptr->pairM.key, keyA))
      ptr = ptr->nextM;

    cursorM = ptr;
  }

  void go_to_first()
  {
    cursorM = headM;
  }

  void step_fwd()
  {
    assert(cursor_ok());
    cursorM = cursorM->nextM;
  }

  void make_empty()
  {
    destroy();
  }

private:
  int sizeM;
  LT_Node<Key, Datum>* headM;
  LT_Node<Key, Datum>* cursorM;

  void destroy()
  {
    while (headM != 0) {
      LT_Node<Key, Datum>* doomed = headM;
      headM = headM->nextM;
      delete doomed;
    }

    cursorM = 0;
    sizeM = 0;
  }

  void copy(const LookupTable<Key, Datum>& source)
  {
    sizeM = 0;
    headM = 0;
    cursorM = 0;

    LT_Node<Key, Datum>* tail = 0;

    for (LT_Node<Key, Datum>* p = source.headM; p != 0; p = p->nextM) {
      LT_Node<Key, Datum>* newNode = new LT_Node<Key, Datum>(p->pairM, 0);

      if (headM == 0)
        headM = newNode;
      else
        tail->nextM = newNode;

      tail = newNode;
      sizeM++;

      if (source.cursorM == p)
        cursorM = newNode;
    }
  }
};

// Generic stream output for any LookupTable whose key and datum are streamable.
template <class Key, class Datum>
ostream& operator<<(ostream& os, const LookupTable<Key, Datum>& lt)
{
  if (lt.cursor_ok())
    os << lt.cursor_key() << "  " << lt.cursor_datum();
  else
    os << "Not Found.";

  return os;
}

#endif
