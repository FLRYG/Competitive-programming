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
typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
int x[200000];
int y[200000];

int main(){
    cin>>N;
    rep(i,N) cin>>x[i]>>y[i];

    vector<int> xid(N,0);
    vector<int> yid(N,0);
    iota(xid.begin(),xid.end(),0);
    iota(yid.begin(),yid.end(),0);
    sort(xid.begin(),xid.end(),[&](int i, int j){ return x[i]<x[j]; });
    sort(yid.begin(),yid.end(),[&](int i, int j){ return y[i]<y[j]; });

    vector<int> d(0);
    map<P,int> m;
    rep(i,N){
        if(m[{xid[0],i}]==0){
            d.push_back(max(abs(x[xid[0]]-x[i]),abs(y[xid[0]]-y[i])));
            // cout<<0<<' '<<i<<endl;
            m[{xid[0],i}]++;
            m[{i,xid[0]}]++;
        }
    }
    rep(i,N){
        if(m[{i,xid[N-1]}]==0){
            d.push_back(max(abs(x[xid[N-1]]-x[i]),abs(y[xid[N-1]]-y[i])));
            // cout<<i<<' '<<N-1<<endl;
            m[{i,xid[N-1]}]++;
            m[{xid[N-1],i}]++;
        }
    }
    rep(i,N){
        if(m[{yid[0],i}]==0){
            d.push_back(max(abs(x[yid[0]]-x[i]),abs(y[yid[0]]-y[i])));
            // cout<<0<<' '<<i<<endl;
            m[{yid[0],i}]++;
            m[{i,yid[0]}]++;
        }
    }
    rep(i,N){
        if(m[{i,yid[N-1]}]==0){
            d.push_back(max(abs(x[yid[N-1]]-x[i]),abs(y[yid[N-1]]-y[i])));
            // cout<<i<<' '<<N-1<<endl;
            m[{i,yid[N-1]}]++;
            m[{yid[N-1],i}]++;
        }
    }
    sort(d.begin(),d.end());

    // repr(e,d) cout<<e<<' ';cout<<endl;
    // repr(e,m) cout<<e.first.first<<' '<<e.first.second<<' '<<e.second<<endl;

    cout<<d[d.size()-2]<<endl;
    
    return 0;
}