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

int N,Q;

void f(int v, int p, vector<vector<int>> &G, int d, vector<vector<int>> &depth, int &k, vector<P> &id){
    depth[d].push_back(k);
    id[v].first=k++;
    repr(e,G[v]){
        if(e!=p) f(e,v,G,d+1,depth,k,id);
    }
    id[v].second=k++;
}

int main(){
    cin>>N;
    vector<vector<int>> G(N,vector<int>());
    repn(i,N-1){
        int p;
        cin>>p;
        p--;
        G[i].push_back(p);
        G[p].push_back(i);
    }
    cin>>Q;

    vector<P> id(N);
    vector<vector<int>> depth(N,vector<int>());
    int k=0;
    f(0,-1,G,0,depth,k,id);

    // rep(i,N){
    //     cout<<i<<": ";
    //     repr(e,depth[i]) cout<<e<<' ';
    //     cout<<endl;
    // }

    while(Q--){
        int U,D;
        cin>>U>>D;
        U--;
        // cout<<id[U].first<<' '<<id[U].second<<endl;
        int ans;
        int l=-1, r=depth[D].size();
        while(r-l>1){
            int m=(l+r)/2;
            if(id[U].first<=depth[D][m]) r=m;
            else l=m;
        }
        ans=-r;
        l=-1, r=depth[D].size();
        while(r-l>1){
            int m=(l+r)/2;
            if(id[U].second<=depth[D][m]) r=m;
            else l=m;
        }
        ans+=r;
        cout<<ans<<endl<<flush;
    }
    
    return 0;
}