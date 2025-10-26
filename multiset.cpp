#include<bits/stdc++.h>
using namespace std;
// Multiset

// contains duplicates and rest elements in sorted order
// we can't access the element by index in multiset, so we use find to get the iterator of the element we want to erase

// for eg:
int main(){
    multiset<int> s = {10, 20, 20, 30};
    auto it = s.find(20);
    if (it != s.end()) {
        cout << "Found: " << *it << endl;  // Found: 20
    }

    s.insert({nums[i]}); // insert the current element into the multiset
    s.erase(s.find(nums[i]));  // if duplicates exist in multiset it will erase only one instance of the element


    *s.begin() -> returns first element of the multiset
    *s.end() -> returns last element of the multiset
    s.empty() -> returns true if the multiset is empty
    s.clear() -> clears the multiset
    s.find(30) -> returns an iterator to the element 30 in the multiset
    // to check if an element exists in the multiset we can use s.find(20) != s.end()
    s.count(10) -> returns the number of instances of 10 in the multiset
}