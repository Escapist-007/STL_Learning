//
//  main.cpp
//  STL_Learning
//  STL : Standard Template Library
//   -- Data Structures and Algorithm
//
//  Created by Md Moniruzzaman Monir on 12/23/18.
//  Copyright © 2018 Md Moniruzzaman Monir. All rights reserved.
//

#include <iostream>

// STL Headers
#include <vector>
#include <deque>
#include <list>
#include <set>  // set and multiset
#include <map>  // map and multimap

#include <unordered_set>   // unordered set/multiset
#include <unordered_map>   // unordered map/multimap

#include <iterator>
#include <algorithm>
#include <numeric>   // some numeric algorithm
#include <functional>

#include <array>


using namespace std;

int main(int argc, const char * argv[]) {
    
                               /*   UNDERSTANDING BASIC CONCEPT OF STL
                                   ======================================
                                                                        */
    
    
    // vector - a common container
    cout << "understanding BASIC STL usage" << endl;
    vector<int> vec;
    
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(23);  // vec: {4, 1, 23}
    
    // iterator for accessing a container
    vector<int>::iterator itr1 = vec.begin();  // half-open : [begin, end)
    vector<int>::iterator itr2 = vec.end();
    
    for(vector<int>::iterator itr = itr1; itr != itr2; itr++)
        cout << *itr << " ";
    cout << endl;
    
    // vec.end() point outside the vector. So we can't access this location
    cout << *vec.end() << endl;  // unknown memory address
    cout << *(vec.end()-1)<< endl; // print : 23
    
    
    // algorithm doesn't work on containers directly. It works on iterator.
    sort(itr1,itr2);
    
    for(vector<int>::iterator itr = itr1; itr != itr2; itr++)
        cout << *itr << " ";
    cout << endl;
    
    
    
    //   CONTAINERS
    // =============
    
    /*
     
     There are 3 types of containers :
     
      1) Sequence containers (array and linked list)
        --- STL provides: vector, deque, list, forward list, array
     
      2) Associative containers (binary tree) [key-value pair and elements are sorted by key]
        --- STL provides:  set, multiset, map, multimap
     
      3) Unordered containers (hash table)
        --- STL provides: unordered_map, unordered_multimap, unordered_set, unordered_multiset
     
    */
    
    
                               // VECTOR -  dynamically allocated contiguous array in memory
    
    cout << endl;
    cout << "      VECTOR  " << endl;
    cout << endl;
    
    vector<int> v;
    cout << "Size is " << v.size() << endl;
    
    v.push_back(1);
    v.push_back(-2);  // v.size() is 2
    
    // Random access in vector
    cout << "Random access in vector" << endl;
    cout << v[1] << endl;  // no range check
    cout << v.at(1) << endl;  // throw range_error exception if index is out of range
    
    cout << v[2] << endl;  // unknown memory address
    // cout << v.at(2) << endl;   // throw error
    
    
    // Accessing all elements
    // option 01 (slower)
    for (int i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    
    // option 02 (universal way of traversing a container), faster
    for(vector<int>::iterator it = v.begin();it != v.end(); it++)
        cout << *it << " ";
    cout << endl;
    
    // option 03 - c++ 11
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    
    int* p = &v[0];
    p[1] = 100;
    cout << p[0] << " " << p[1] << endl;
    
    // common API (member functions) for all containers
    cout << "common API's usage" << endl;
    
    if(!v.empty())
        cout << v.size() << endl;
    
    vector<int> v2(v); // copy constructor, v2 = {1,100}
    
    for( auto i: v2)
        cout << i << " ";
    cout << endl;
    
    v.clear(); // remove all items in v
    v2.swap(v); // v2 now becomes empty
    
    cout << v2.size() << endl;
    
    /*
     
     PROPERTIES OF VECTOR:
     =====================
     1. Fast insert/remove at the end: O(1)
     2. Slow insert/remove at the begining or in the middle: O(n)  because all other elements have to shifted one slot
     3. Slow search: O(n)
     
     */
    
    
                                // DEQUE - almost like vector but grows in two direction - not contagious
    
    cout << endl;
    cout << "      DEQUE   " << endl;
    cout << endl;
    
    
    deque<int> d = {1,2};
    d.push_back(3);
    d.push_front(-1);
    
    for(auto i: d)
        cout << i << " ";
    cout << endl;
    
    cout << "Size is " << d.size() << endl;
    cout << d[2] << endl;
    
    
    /*
     
     PROPERTIES OF DEQUE:
     =====================
     1. Fast insert/remove at the begining and the end: O(1)
     2. Slow insert/remove at the begining or in the middle: O(n)  because all other elements have to shifted one slot
     3. Slow search: O(n)
     
     */
    
    
                               // LIST - Doubly Linked List
    
    cout << endl;
    cout << "      LIST     "  << endl;
    cout << endl;
    
    list<int> l = {11,2,45};
    l.push_back(12);
    l.push_front(21);   // l = {21, 11, 2, 45, 12}
    
    list<int>::iterator it = find(l.begin(), l.end(),11);  // find() is an algorithm which will return an iterator pointing to the element 11
    cout << *it << endl;  // 11
    
    // faster insertion than vector/deque. take O(1) time
    l.insert(it, 8);  // l = {21, 8, 11, 2, 45, 12}
    

    for(auto i: l)
        cout << i << " ";
    cout << endl;
    
    l.erase(it);  // removd 11 . take O(1) time
    
    for(auto i: l)
        cout << i << " ";
    cout << endl;
    
    
    /*
     
     PROPERTIES OF LIST:
     =====================
     1. Fast insert/remove at any place : O(1)
     2. Slow search: O(n). Its is slower than vector/deque because its not contagious (no cache benfit, lots of cache miss). So no locality of memory.
     3. No random access. no [] operator.
     
     */
    
    // special function of list : splice()
    list<int> l2 = {1,2,3};
    list<int>::iterator itr = l2.end();
    
    l2.splice(itr, l, l.begin(),  l.end());  // l2 = {1,2,3,21,8,2,45,12}
    
    for(auto i: l2)
        cout << i << " ";
    cout << endl;
    
                                 // ARRAY
    
    cout << endl;
    cout << "      ARRAY     "  << endl;
    cout << endl;
    
    
    // a and b are different type as their size is not same. Drawback of array container
    array<int, 3> a = {2,3,4};
    array<int, 4> b = {1,2,3,4};
    
    cout << a[1] << endl;
    cout << b.size() << endl;
    
    
                               // SET & MULTISET - Associative Container
    cout << endl;
    cout << "      SET     "  << endl;
    cout << endl;
    
    
    set<int> s;
    
    s.insert(23);
    s.insert(3);
    s.insert(5029);  // s = {3, 23, 5029} , insertion time : O(log(n))
    
    // Elements are always sorted and no duplicate. Set is implemented using binary tree.
    
    set<int>::iterator itrr;
    
    itrr = s.find(23);  // find() will find the element 23 and return an iterator
    
    cout << *itrr << endl;
    
    pair <set<int>::iterator, bool> ret;
    
    ret = s.insert(23);   // insert() will return a pair (iterator, boolean value). If the element is inserted then the boolean value will be true.
                          // iterator in the pair always point the element in the set.
    // Here, 23 won't be inserted as 23 is already in s.
    
    cout << "Returned pair : " << "Iterator's value - " << *ret.first << ", " << "Boolean Value - " << ret.second << endl;
    
    if(ret.second==false)
        itrr = ret.first;
    
    s.insert(itrr,1105023);  // Here, itrr just give a hint to insert() method for insertion. Like it can decrease the time from O(log(n)) to o(1) at best.
                             // But itrr still points to 23. s = {3, 23, 5029, 1105023}
    
    cout << "Before caliing erase() :" <<endl;
    for(auto i: s)
        cout << i << " ";
    cout << endl;
    
    s.erase(itrr); // Remove 23
    
    cout << "After caliing erase() :" <<endl;
    for(auto i: s)
        cout << i << " ";
    cout << endl;
    
    
    
    cout << endl;
    cout << "      MULTISET     "  << endl;
    cout << endl;
    
    
    
    // multiset is a set that allows duplicate items
    multiset<int> ms = {1,1,2,2,3};
    
    cout << "Elements in a multiset" <<endl;
    
    for(auto i: ms)
        cout << i << " ";
    cout << endl;
    
    // set/multiset : Value of the elements can't be updated.
    
    itrr = ms.find(2);  // returns the first occurence of 2
    
    cout<< *itrr <<endl;
    // *itrr = 50; --> Not possible . Read-only value because if it is allowed then whole tree structure will be corrupted
    
    ms.erase(itrr);
    
    for(auto i: ms)
        cout << i << " ";
    cout << endl;
    
    
    /*
     
     PROPERTIES OF SET/MULTISET:
     =====================
     1. Fast searche : O(log(n))
     2. Traversing is slow. Same locality problem like list.
     3. No random access. no [] operator.
     
     */
    
                                  // MAP & MULTIMAP - Associative Container
    cout << endl;
    cout << "      MAP     "  << endl;
    cout << endl;
    
    
    map<char,int> mp;
    
    mp.insert( pair<char,int>('a',97) );
    mp.insert( make_pair('a', 97));  // This is convenient for inserting a pair. Map is sorted by key and no duplicate key is allowed
    mp.insert( make_pair('b', 98));  // mp = { (a,97), (b, 98) }
    
    cout << "Printing the elements in map" <<endl;
    
    for(auto i: mp)
        cout << i.first << " " << i.second << endl;
    cout << endl;
    
    map<char,int>::iterator itrrr = mp.end();
    mp.insert(itrrr, make_pair('c',99));   // 'itrrr' is giving hint for insertion
    
    for(auto i: mp)
        cout << i.first << " " << i.second << endl;
    cout << endl;
    
    itrrr = mp.find('b');
    
    cout<< (*itrrr).first << " " << (*itrrr).second <<endl;
    
    
    
    
    cout << endl;
    cout << "      MULTIMAP    "  << endl;
    cout << endl;
    
    
    // multimap is a map that allows duplicate keys
    multimap<char,int> mm;
    
    mm.insert( make_pair('a',99));
    mm.insert( make_pair('a',99));
    
    cout << "Elements in a multimap" <<endl;
    
    for(auto i: mm)
        cout << i.first << " " << i.second <<endl;
    cout << endl;
    
    // map/multimap : Value of the keys can't be updated.
    
    
    return 0;
}
