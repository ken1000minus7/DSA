#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// stl - standard template library contains containers, algorithms and iterators already implemented that can be used by us directly
// containers are used to store data
// stl contains generic containers and these containers are of 2 types
// 1. sequential containers - store data in a linear fashion like vector, array, list, stack, queue etc;
// 2. associative containers - don't store linearly, require a key to access data like map, unordered_map, set, unordered_set, multiset etc
int main()
{
    vector<int> v;
    // size() a member function of container v
    int a = v.size();

    // sort is a function of stl
    sort(v.begin(),v.end());
    // v.begin() returns the iterator of the first element of the vector
    // iterators are like pointers, they are used to access data from a container
    // many types of iterator exist
    return 0;
}