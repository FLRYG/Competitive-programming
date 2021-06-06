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

int N,M;

void f(int v, vector<int> &chk, vector<vector<int>> &G){
    chk[v]=1;
    repr(e,G[v]){
        if(chk[e]==0) f(e,chk,G);
    }
}

int main(){
    cin>>N>>M;
    vector<vector<int>> G(N);
    rep(i,M){
        int a,b;
        cin>>a>>b;
        G[a-1].push_back(b-1);
    }

    int ans=0;
    rep(i,N){
        vector<int> chk(N,0);
        f(i,chk,G);
        repr(e,chk) ans+=e;
    }

    cout<<ans<<endl;

    return 0;
}