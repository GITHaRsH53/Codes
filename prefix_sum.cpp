#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &it:v)cin>>it;
    vector<ll>prefix_sum(n);
    prefix_sum[0]=v[0];
    for(int i=1;i<n;i++){
        prefix_sum[i]=prefix_sum[i-1]+v[i];
    }
    int l,r;
    cin>>l>>r;
    cout<<prefix_sum[r]-(l==0 ? 0 : prefix_sum[l-1])<<endl;
}
