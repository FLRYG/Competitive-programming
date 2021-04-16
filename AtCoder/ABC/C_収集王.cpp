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

int R,C,K,N;

int main(){
    cin>>R>>C>>K>>N;
    vector<vector<int>> h(R,vector<int>());
    vector<vector<int>> v(C,vector<int>());
    rep(i,N){
        int r,c;
        cin>>r>>c;
        r--, c--;
        h[r].push_back(c);
        v[c].push_back(r);
    }

    sort(h.begin(),h.end(),[&](int i, int j){ return h[i].size()<h[j].size(); });
    sort(v.begin(),v.end(),[&](int i, int j){ return v[i].size()<v[j].size(); });

    ll ans=0;
    rep(i,R){
        int cnth=h[i].size();
        int cntv=0;
        int ng=-1, ok=C;
        while(ok-ng>1){
            int m=(ng+ok)/2;
            if(v[m]<K-cnth)
        }
    }
    
    return 0;
}