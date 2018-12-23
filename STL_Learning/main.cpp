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


using namespace std;

int main(int argc, const char * argv[]) {
    
    //   UNDERSTANDING BASIC CONCEPT OF STL
    //  ======================================
    
    // vector - a common container
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
    
    
    
    return 0;
}
