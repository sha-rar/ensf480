// ENSF 480 - Lab 3, Ex C
// M. Moussavi

#include <assert.h>
#include <cstring>
#include <iostream>
#include "lookupTable.h"
#include "customer.h"

using namespace std;

template <class Key, class Datum>
void print(LookupTable<Key, Datum>& lt)
{
  if (lt.size() == 0)
    cout << "  Table is EMPTY.\n";

  for (lt.go_to_first(); lt.cursor_ok(); lt.step_fwd())
    cout << lt << endl;
}

template <class Key, class Datum>
void try_to_find(LookupTable<Key, Datum>& lt, const Key& key)
{
  lt.find(key);

  if (lt.cursor_ok())
    cout << "\nFound key:" << lt;
  else
    cout << "\nSorry, I couldn't find key: " << key << " in the table.\n";
}

void test_Customer();
void test_String();
void test_integer();

int main()
{
  test_Customer();
  test_String();
  test_integer();

  cout << "\n\nProgram terminated successfully.\n\n";
  return 0;
}

void test_Customer()
{
  cout << "\nCreating and testing Customers LookupTable <int, Customer> .....\n";
  LookupTable<int, Customer> lt;

  Customer a("Joe", "Morrison", "11 St. Calgary.", "(403)-1111-123333");
  Customer b("Jack", "Lewis", "12 St. Calgary.", "(403)-1111-123334");
  Customer c("Tim", "Hardy", "13 St. Calgary.", "(403)-1111-123335");

  lt.insert(Pair<int, Customer>(8002, a));
  lt.insert(Pair<int, Customer>(8004, c));
  lt.insert(Pair<int, Customer>(8001, b));

  assert(lt.size() == 3);
  lt.remove(8004);
  assert(lt.size() == 2);

  cout << "\nPrinting table after inserting 3 new keys and 1 removal...\n";
  print(lt);

  cout << "\nLet's look up some names ...\n";
  try_to_find(lt, 8001);
  try_to_find(lt, 8000);

  cout << "\nTesting and using iterator ...\n";
  typename LookupTable<int, Customer>::Iterator it = lt.begin();
  cout << "\nThe first node contains: " << *it << endl;

  while (!it)
    cout << ++it << endl;

  lt.go_to_first();
  lt.step_fwd();
  LookupTable<int, Customer> clt(lt);
  assert(strcmp(clt.cursor_datum().getFname(), "Joe") == 0);

  cout << "\nTest copying: keys should be 8001, and 8002\n";
  print(clt);
  lt.remove(8002);

  clt = lt;

  cout << "\nTest assignment operator: key should be 8001\n";
  print(clt);

  lt.make_empty();
  cout << "\nPrinting table for the last time: Table should be empty...\n";
  print(lt);

  cout << "***----Finished tests on LookupTable <int, Customer>-----***\n";
}

void test_String()
{
  cout << "\nCreating and testing LookupTable <int, Mystring> .....\n";
  LookupTable<int, Mystring> lt;

  Mystring a("I am an ENEL-409 student.");
  Mystring b("C++ is a powerful language for engineers but it's not easy.");
  Mystring c("Winter 2004");

  lt.insert(Pair<int, Mystring>(8002, a));
  lt.insert(Pair<int, Mystring>(8001, b));
  lt.insert(Pair<int, Mystring>(8004, c));

  assert(lt.size() == 3);
  lt.remove(8004);
  assert(lt.size() == 2);

  cout << "\nPrinting table after inserting 3 new keys and 1 removal...\n";
  print(lt);

  cout << "\nLet's look up some names ...\n";
  try_to_find(lt, 8001);
  try_to_find(lt, 8000);

  typename LookupTable<int, Mystring>::Iterator it = lt.begin();
  cout << "\nThe first node contains: " << *it << endl;

  while (!it)
    cout << ++it << endl;

  lt.go_to_first();
  lt.step_fwd();
  LookupTable<int, Mystring> clt(lt);
  assert(strcmp(clt.cursor_datum().c_str(), "I am an ENEL-409 student.") == 0);

  cout << "\nTest copying: keys should be 8001, and 8002\n";
  print(clt);
  lt.remove(8002);

  clt = lt;

  cout << "\nTest assignment operator: key should be 8001\n";
  print(clt);

  lt.make_empty();
  cout << "\nPrinting table for the last time: Table should be empty ...\n";
  print(lt);

  cout << "***----Finished Lab 3 tests on <int, Mystring>-----***\n";
}

void test_integer()
{
  cout << "\nCreating and testing LookupTable <int, int> .....\n";
  LookupTable<int, int> lt;

  lt.insert(Pair<int, int>(8002, 9999));
  lt.insert(Pair<int, int>(8001, 8888));
  lt.insert(Pair<int, int>(8004, 8888));

  assert(lt.size() == 3);
  lt.remove(8004);
  assert(lt.size() == 2);

  cout << "\nPrinting table after inserting 3 new keys and 1 removal...\n";
  print(lt);

  cout << "\nLet's look up some names ...\n";
  try_to_find(lt, 8001);
  try_to_find(lt, 8000);

  typename LookupTable<int, int>::Iterator it = lt.begin();
  cout << "\nThe first node contains: " << *it << endl;

  while (!it)
    cout << ++it << endl;

  lt.go_to_first();
  lt.step_fwd();
  LookupTable<int, int> clt(lt);
  assert(clt.cursor_datum() == 9999);

  cout << "\nTest copying: keys should be 8001, and 8002\n";
  print(clt);
  lt.remove(8002);

  clt = lt;

  cout << "\nTest assignment operator: key should be 8001\n";
  print(clt);

  lt.make_empty();
  cout << "\nPrinting table for the last time: Table should be empty ...\n";
  print(lt);

  cout << "***----Finished Lab 3 tests on <int, int>-----***\n";
}
