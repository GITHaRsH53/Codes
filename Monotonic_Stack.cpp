#include <bits/stdc++.h>
using namespace std;

//next smaller left(NSL)     // empty stack signifies that there is no left element existing that is smaller to curr element 
//  9   2  5 3 6   1  8  10  -> array
// -1  -1  2 2 3  -1  1  8  -> ans (NSL)

// v & ans & stack:
// 9     (-1) [9]
// 2     (-1) 9>=2 pop 9 and push curr element i.e. 2 for finding the next smaller element thats why we push current element  [2]
// 5     (2)  topmost element is the answer i.e. 2 . now just push 5  [2,5]
// 3     (2)  as 5>=3 pop 5 , but 2 is not >=3 and push 3 [2,3]
// 6     (3)  as 3 is not >=6, and the closest is 3, now push 6 in stack [2,3,6]
// 1     (-1) as 6,3,5,2,9 all greater than 1 , so pop all and push 1  [1]
// 8     (1) as 1 is not >=8, now push 8  [1,8]
// 10    (8) as 8 is not >=10 , now push 10. [1,8,10]

//TC -> O(N)

int main() {
	// your code goes here
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &it:v) cin >> it;
    stack<int> s;
    vector<int>ans(n);
    for(int i=0; i<n; i++){
        while(!s.empty() and s.top()>=v[i]){
            s.pop();
        }
        if(s.empty()) ans[i] = -1;
        else ans[i] = s.top();
        s.push(v[i]);
    }
    for(auto &it:ans) cout << it << " ";
    cout << endl;
}

//next smaller right(NSR)
int main() {
	// your code goes here
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &it:v) cin >> it;
    stack<int> s;
    vector<int>ans(n);
    for(int i=n-1; i>=0; i--){
        while(!s.empty() and s.top()>=v[i]){
            s.pop();
        }
        if(s.empty()) ans[i] = -1;
        else ans[i] = s.top();
        s.push(v[i]);
    }
    for(auto &it:ans) cout << it << " ";
    cout << endl;
}

//next greater left(NGL)
int main() {
	// your code goes here
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &it:v) cin >> it;
    stack<int> s;
    vector<int>ans(n);
    for(int i=0; i<n; i++){
        while(!s.empty() and s.top()<v[i]){
            s.pop();
        }
        if(s.empty()) ans[i] = -1;
        else ans[i] = s.top();
        s.push(v[i]);
    }
    for(auto &it:ans) cout << it << " ";
    cout << endl;
}

//next greater right(NGR)
int main() {
	// your code goes here
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &it:v) cin >> it;
    stack<int> s;
    vector<int>ans(n);
    for(int i=n-1; i>=0; i--){
        while(!s.empty() and s.top()<v[i]){
            s.pop();
        }
        if(s.empty()) ans[i] = -1;
        else ans[i] = s.top();
        s.push(v[i]);
    }
    for(auto &it:ans) cout << it << " ";
    cout << endl;
}
