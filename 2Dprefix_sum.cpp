#include<bits/stdc++.h>
using namespace std;

#define ll long long

// first calculate sum till each box.
// then calculate sum between 2 box (r1,c1) and (r2,c2).
int main(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>>v(n, vector<ll>(m));
    for (auto &i : v) {
        for (auto &j : i)cin >> j;
    }
    vector<vector<ll>>pre(n, vector<ll>(m, 0));
    pre[0][0] = v[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)continue;
            pre[i][j] += v[i][j];           
            if (j > 0) {
                pre[i][j] += pre[i][j - 1]; // sum of all col values left of jth col
            }
            if (i > 0) {
                pre[i][j] += pre[i - 1][j]; // sum of all row values above ith row
            }
            if (i > 0 && j > 0) {
                pre[i][j] -= pre[i - 1][j - 1]; // repeated part 
            }
        }
    }
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << pre[r2][c2] - (r1>0 ? pre[r1 - 1][c2] : 0) - (c1>0 ? pre[r2][c1 - 1]:0) + (r1>0 && c1>0 ? pre[r1 - 1][c1 - 1] : 0); // draw matrix ans see
}