// find the smallest prime factor(spf) of any n
// here we get the spf for each index(index represent the number) except 0 and 1

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 100;
    vector<int> spf_sieve(n,0);
    for(int i=2;i<=n;i++){
            spf_sieve[i]=i;
    }
    for(int i=2;i*i<=n;i++){   //n(log(log(n)))
        if(spf_sieve[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(spf_sieve[j]==j) spf_sieve[j]=i;
            }
        }
    }
    cout << spf_sieve[18];
}


