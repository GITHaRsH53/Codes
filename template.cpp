#include<bits/stdc++.h> 
using namespace std;
#define ll long long 
#define pb push_back
#define all(v) v.begin(),v.end()
#define countsb(n) __builtin_popcount(n)
#define maxele_v(v) *max_element(v.begin(),v.end()) //return value of the pointer
#define desc_sortv(v) sort(v.rbegin(),v.rend()) //or use this sort(v.begin(),v.end(),greater<int>())
#define rev_v(v) reverse(v.begin(),v.end()) //same for string
#define erase_v(v,i) v.erase(v.begin()+i)
#define erase_range_v(v,i,j) v.erase(v.begin()+i,v.begin()+j)
#define insert_v(v,pos,val) v.insert(v.begin()+pos,val)
#define sum_v(v) accumulate(v.begin(),v.end(),0) // 0 -> initial value 
#define unique_v(v) v.resize(unique(v.begin(),v.end())-v.end()) // (ON SORTED VECTOR)gives all the unique elements in vector. (same for string)
#define erasestring(s,pos,lengthtobe_deletedafterpos) s.erase(pos,lengthtobedeletedafterpos)
#define gcd(a,b) __gcd(a,b)

const int mod = 1e9+7;// prime number 

//binary exponentiation -> used for finding power big integers
ll bin_expo(ll a, ll b, ll mod) {  // log b time -> iterative approach, prove it by example
    ll res = 1; 
    while (b > 0) {
        if (b & 1) res = (res * a) % mod; // if b is odd
        a = (a * a) % mod; // b -> even
        b = b >> 1; //b = b/2;
    }
    return res;
} 
ll inverse(ll b, ll m) {return bin_expo(b, m - 2, m);}  // b^-1 by fermats little theorem
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}  // +m to handle negative numbers
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, inverse(b, m), m) + m) % m;}

vector<string> allpermutaions(string s){  // all permutations of s
    vector<string> ans;   // tc = n*n!
    sort(all(s));
    do{
        // if(s[0]!='0')
        ans.pb(s);
    }while(next_permutation(s.begin(),s.end()));
    return ans;
}

ll gcd(ll a,ll b){  // if a>b;
    if(b==0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a, ll b){
    if(b==0) return a;
    return a*b/gcd(a,b);
}

//priority_queue<//type of element to be stored//> pq
priority_queue<pair<int,int>> max_pq;   
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_pq;

class compare{  //custom priority queue function // gives oppsite of vector or normal comparisions 
    public:
    bool operator()(const pair<ll,ll> &p1,const pair<ll,ll> &p2){    
        // return true if p1 has less priority than p2
        if(max(p1.first,p1.second)==max(p2.first,p2.second)) return min(p1.first,p1.second) < min(p2.first,p2.second);
        return max(p1.first,p1.second)<max(p2.first,p2.second);
    }
};

priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;

const int N = 1000100;
vector<ll>sieve(N,0);

void solve() {
    
}



int main() {
    // sieve[0]=1;
    // for(int i=2; i*i<=N; i++){   
    //     if(!sieve[i]){
    //         for(int j = i*i; j<=N; j+=i){
    //             sieve[j]=1;
    //         }
    //     }
    // }
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}