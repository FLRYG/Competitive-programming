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

int N;
int C[100000];

void f(int prev, int p, vector<vector<int>> &G, vector<int> &cnt, vector<int> &ans){
    cnt[C[p]]++;
    if(cnt[C[p]]<=1) ans.push_back(p+1);
    repr(e,G[p]){
        if(e==prev) continue;
        f(p,e,G,cnt,ans);
    }
    cnt[C[p]]--;
}

int main(){
    cin>>N;
    rep(i,N) cin>>C[i];
    vector<vector<int>> G(N,vector<int>(0));
    rep(i,N-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> ans(0);
    vector<int> cnt(100001,0);
    f(-1,0,G,cnt,ans);

    sort(ans.begin(),ans.end());

    repr(e,ans) cout<<e<<endl;
    
    return 0;
}