// trial divison method to find prime factors of a number
// O(sqrt(n) + log(n)) time complexity

#include<bits/stdc++.h> 
using namespace std;

void solve(){    
    int n;
    cin >> n;
    vector<int> fact;
    for(int d=2; d*d<=n; d++){  // iterate till sqrt(n)
        if(n%d==0){   // divisible by 2
            fact.push_back(d);
            while(n%d==0){ // O(log(n)) time complexity  for entire for loop as  // remove all the multiples of 2(similarly for 3,4,etc)
                n/=d;
            }
        }
    }
    if(n>1) fact.push_back(n); // at last if n is left as prime number then add it to the list
    for(auto &it:fact)  cout << it << " ";

}

int main() {
    int t = 1;
    // cin >> t;
    for(int i = 0; i < t; i++) {
    	solve();
    }
    return 0;
}
