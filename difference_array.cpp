//helps in adding values to array in O(n)+q time for q queries
//add val from range l to r in given array
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n;
    cin>>n;
    vector<ll>v(n);
    for(auto &it:v)cin>>it;
    vector<ll>diff(n,0);
    int q;
    cin>>q;
    while(q--){           // diff array
        int l,r;cin>>l>>r;
        ll val;cin>>val;
        diff[l]+=val;
        if(r+1<n){
            diff[r+1]-=val;
        }
    }
    for(int i=1;i<n;i++){  //prefix sum 
        diff[i]+=diff[i-1];
    }
    for(int i=0;i<n;i++){  //final addition
        v[i]+=diff[i];
    }
}
