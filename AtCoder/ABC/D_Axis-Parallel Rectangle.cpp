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

ll N,K;
ll x[50];
ll y[50];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>x[i]>>y[i];

    vector<int> id(N,0);
    iota(id.begin(),id.end(),0);
    sort(id.begin(),id.end(),[](int i, int j){ return x[i]<x[j]; });

    ll ans=5*LINF;
    rep(i,N-K+1){
        vector<ll> v(0);
        v.reserve(N);
        for(int j=i;j<N;j++){
            v.push_back(id[j]);
            if(v.size()<K) continue;
            sort(v.begin(),v.end(),[](int i, int j){ return y[i]<y[j]; });
            rep(k,v.size()-K+1){
                ll s=x[id[j]]-x[id[i]];
                s*=y[v[k+K-1]]-y[v[k]];
                // cout<<s<<endl;
                ans=min(ans,s);
            }
        }
    }

    cout<<ans<<endl;
    
    return 0;
}