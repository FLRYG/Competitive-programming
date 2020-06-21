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

ll N;
map<ll,ll> A;
ll Q;
ll B[100000], C[100000];
ll ans;

int main(){
    cin>>N;
    rep(i,N){
        ll a;
        cin>>a;
        A[a]++;
        ans+=a;
    }
    cin>>Q;
    rep(i,Q) cin>>B[i]>>C[i];

    rep(i,Q){
        ans+=(C[i]-B[i])*A[B[i]];
        A[C[i]]+=A[B[i]];
        A[B[i]]=0;

        cout<<ans<<endl;
    }
}