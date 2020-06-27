#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;

ll N,M,K;
ll A[200001], B[200001];

int main(){
    cin>>N>>M>>K;
    repn(i,N) cin>>A[i];
    repn(i,M) cin>>B[i];

    repn(i,N) A[i]+=A[i-1];
    repn(i,M) B[i]+=B[i-1];

    ll ans=0;
    rep(i,N+1){
        if(A[i]>K) continue;
        ll res=i;
        ll time=K-A[i];
        auto p=lower_bound(B,B+M+1,time+1);
        res+=(p-B)-1;
        ans=max(ans,res);
    }

    cout<<ans<<endl;
}