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
string S[200000]; 

int f(int v, vector<vector<int>> &G, vector<int> &chk){
    if(chk[v]==0 || chk[v]==1 || chk[v]==INF) return chk[v];
    if(chk[v]==-2) return INF;
    if(G[v].size()==0) return 1;
    chk[v]=-2;
    int res=1, cnt=0;
    repr(e,G[v]){
        int c=f(e,G,chk);
        if(c!=INF) res&=c;
        else cnt++;
    }
    if(cnt==G[v].size()) return INF;
    // if(cnt && res) return INF;
    res=!res;
    return chk[v]=res;
}

int main(){
    cin>>N;
    rep(i,N) cin>>S[i];

    vector<string> A(N), B(N);
    map<string,int> m;
    rep(i,N){
        A[i]=S[i].substr(0,3);
        B[i]=S[i].substr(S[i].size()-3,3);
        m[A[i]], m[B[i]];
    }
    int NN=0;
    repr(e,m) e.second=NN++;

    vector<vector<int>> G(NN);
    rep(i,N){
        G[m[A[i]]].push_back(m[B[i]]);
    }

    vector<int> chk(NN,-1);
    // rep(i,NN) f(i,G,chk);
    rep(i,N){
        int k=f(m[B[i]],G,chk);
        // int k=chk[m[A[i]]];
        if(k==1) cout<<"Takahashi"<<endl;
        else if(k==0) cout<<"Aoki"<<endl;
        else cout<<"Draw"<<endl;
    }

    return 0;
}