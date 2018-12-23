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
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
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
    
    
    return 0;
}
