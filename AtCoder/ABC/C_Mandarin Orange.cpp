#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
int A[10000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    vector<int> L(N),R(N);
    stack<int> s,ss;
    rep(i,N){
        while(!s.empty() && A[s.top()]>=A[i]) s.pop();
        L[i]=s.size()==0?0:(s.top()+1);
        s.push(i);
    }
    for(int i=N-1;i>=0;i--){
        while(!ss.empty() && A[ss.top()]>=A[i]) ss.pop();
        R[i]=ss.size()==0?N:ss.top();
        ss.push(i);
    }

    int ans=0;
    rep(i,N){
        ans=max(ans,A[i]*(R[i]-L[i]));
    }

    cout<<ans<<endl;

    return 0;
}

// int N;
// int A[10000];

// int main(){
//     cin>>N;
//     rep(i,N) cin>>A[i];

//     int ans=0;
//     rep(l,N){
//         int h=A[l];
//         for(int r=l;r<N;r++){
//             h=min(h,A[r]);
//             ans=max(ans,h*(r-l+1));
//         }
//     }

//     cout<<ans<<endl;

//     return 0;
// }