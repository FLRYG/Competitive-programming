#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <chrono>
#include <random>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
// typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N,W,C;
ll L[100000];
ll R[100000];
ll P[100000];

int main(){
    cin>>N>>W>>C;
    rep(i,N) cin>>L[i]>>R[i]>>P[i];

    vector<ll> G;
    rep(i,N){
        G.push_back(max(0LL,L[i]-C+1));
        G.push_back(R[i]);
    }
    sort(G.begin(),G.end());
    G.erase(unique(G.begin(),G.end()),G.end());

    vector<ll> sum(G.size(),0);
    rep(i,N){
        ll idl=(ll)(lower_bound(G.begin(),G.end(),max(0LL,L[i]-C+1))-G.begin());
        ll idr=(ll)(lower_bound(G.begin(),G.end(),R[i])-G.begin());
        sum[idl]+=P[i];
        sum[idr]-=P[i];
    }

    rep(i,sum.size()-1){
        sum[i+1]+=sum[i];
    }

    // repr(e,G) cout<<e<<' '; cout<<endl;
    // repr(e,sum) cout<<e<<' '; cout<<endl;

    ll ans=LINF;
    rep(i,sum.size()){
        if(G[i]+C<=W) ans=min(ans,sum[i]);
    }

    cout<<ans<<endl;
    
    return 0;
}