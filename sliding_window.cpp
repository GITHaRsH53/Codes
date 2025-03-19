#include <bits/stdc++.h>
using namespace std;

//e.g. used here is maxsubarray sum of size k using sliding window


int MaxSubarraySumOfSizeK(vector<int>& a, int k){
    int n = a.size();
    int sum=0, ans=0;

    for(int i=0; i<k; i++){
        sum += a[i];
        if(i>=k) sum -= a[i-k];
        if(i>=k-1) ans = max(ans, sum);
    }
}


// OR

int MaxSubarraySumOfSizeK(vector<int>& a, int k){
    int n = a.size();
    int sum=0, ans=0;

    for(int i=0; i<k; i++){
        sum += a[i];
    }

    for(int i=k; i<n; i++){
        sum += a[i]; 
        sum -= a[i-k];
        ans = max(ans, sum);
    }
}