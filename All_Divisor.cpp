//total no. of divisors for n (optimized - O(squareroot(n)))
//if divisors_count == 2 then prime
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    int n = 16;
    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            v.push_back(i);
            if(i!=n/i) v.push_back(n/i); // for (4*4=16) and (if n==12 then for 4*3=12)
        }
    }
    for(auto &it:v) cout << it << " ";
    // v->{1,16,2,8,4} -> output
}