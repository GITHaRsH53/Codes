#include<bits/stdc++.h> 
using namespace std;
#define ll long long 

const int mod = 1e9+7;// prime number 

//binary exponentiation -> used for finding power big integers
//iterative approach
ll bin_expo(ll a, ll b, ll mod) {  // log b time -> iterative approach, prove it by example
    ll res = 1; 
    while (b > 0) {
        if (b & 1) res = (res * a) % mod; // if b is odd make it even
        a = (a * a) % mod; // b -> even
        b = b >> 1; //b = b/2;
    }
    return res;
}

//recursive approach
ll binpow(ll a, ll b) {
    if (b == 0) return 1;
    ll res = binpow(a, b / 2);
    res = (res * res) % mod;
    if (b % 2) res = (res * a) % mod;
    return res;
}

// modulo arithmetic
ll inverse(ll b, ll m) {return bin_expo(b, m - 2, m);}  // b^-1 mod m or b^m-2 mod m by fermats little theorem
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}  // +m to handle negative numbers
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, inverse(b, m), m) + m) % m;}


//modular divison  -> convert to modular multiplication
//a/b = a * b^(-1)  //now we want b^(-1) mod N 
// by fermats theorem:
//      a^(p-1) = 1 mod p    p is prime and a and p are coprime
//      a^(p-2) = a^-1 mod p
//this implies a^-1 mod p = a^(p-2) mod p now we have to calculate this using bin_expo
