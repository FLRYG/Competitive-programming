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
typedef pair<ll,ll> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

P f(int v, int p, vector<vector<int>> &G){
    P res={1,1};
    repr(e,G[v]){
        if(e!=p){
            P q=f(e,v,G);
            res.first*=(q.first+q.second)%MOD;
            res.second*=q.first;
            res.first%=MOD;
            res.second%=MOD;
        }
    }
    return res;
}

int N;

int main(){
    cin>>N;
    vector<vector<int>> G(N);
    rep(i,N-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    P p=f(0,-1,G);
    ll ans=(p.first+p.second)%MOD;
    cout<<ans<<endl;
    
    return 0;
}