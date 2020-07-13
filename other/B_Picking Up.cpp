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
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;

ll N;
ll x[50], y[50];

int main(){
    cin>>N;
    rep(i,N) cin>>x[i]>>y[i];

    map<P,ll> m;
    rep(i,N){
        rep(j,N){
            if(i==j) continue;
            m[P(x[i]-x[j],y[i]-y[j])]++;
        }
    }

    ll ans=0;
    repr(e,m){
        ans=max(ans,e.second);
    }
    ans=N-ans;

    cout<<ans<<endl;
}