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

ll N;
ll a[200000];
ll b[200000];
vector<ll> G[200000];
ll dist[200000];
ll Q;
ll C[200000];

void dfs1(ll pos, ll parent){
    if(pos==0) dist[pos]=0;
    else dist[pos]=dist[parent]+1;
    repr(e,G[pos]){
        if(e==parent) continue;
        dfs1(e,pos);
    }
}

void dfs2(ll pos, ll parent){
    if(pos!=0) C[pos]+=C[parent];
    repr(e,G[pos]){
        if(e==parent) continue;
        dfs2(e,pos);
    }
}

int main(){
    cin>>N;
    rep(i,N-1){
        cin>>a[i]>>b[i];
        a[i]--;
        b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    dfs1(0,-1);
    cin>>Q;

    ll t,e,x;
    while(Q--){
        cin>>t>>e>>x;
        e--;
        if(t==1){
            if(dist[a[e]]<dist[b[e]]){
                C[0]+=x;
                C[b[e]]-=x;
            }else{
                C[a[e]]+=x;
            }
        }else{
            if(dist[a[e]]<dist[b[e]]){
                C[b[e]]+=x;
            }else{
                C[0]+=x;
                C[a[e]]-=x;
            }
        }
    }
    dfs2(0,-1);

    rep(i,N) cout<<C[i]<<endl;

    return 0;
}