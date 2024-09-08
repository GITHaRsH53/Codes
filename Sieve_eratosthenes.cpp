// to find all primes till n  (constrains n<=1e7)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 100;
    vector<int> sieve(n,0);
    for(int i=2;i<=n;i++){
            sieve[i]=1;
    }
    for(int i=2;i*i<=n;i++){   //n(log(log(n)))
        if(sieve[i]){
            for(int j=i*i;j<=n;j+=i){  //skip by i
                sieve[j]=0;
            }
        }
    }
    for(int i=2; i<=n; i++){
        if(sieve[i]) cout << i << " ";
    }
    // output -> {2, 3, 5, 7, 11, 13, 17, 19}
}
