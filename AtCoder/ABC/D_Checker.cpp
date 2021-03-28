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

int N,K;
int x[100000];
int y[100000];
int c[100000];
int K2;

int f(vector<vector<int>> &G, int x1, int y1, int x2, int y2){
    int res=0;
    if(x1<=x2 && y1<=y2){
        res+=G[x2][y2]-G[x1-1][y2]-G[x2][y1-1]+G[x1-1][y1-1];
    }else if(x1<=x2){
        res+=f(G,x1,y1,x2,K2)+f(G,x1,1,x2,y2);
    }else if(y1<=y2){
        res+=f(G,x1,y1,K2,y2)+f(G,1,y1,x2,y2);
    }else{
        res+=f(G,x1,y1,K2,K2)+f(G,x1,1,K2,y2)
            +f(G,1,1,x2,y2)+f(G,1,y1,x2,K2);
    }
    return res;
}

int main(){
    cin>>N>>K;
    rep(i,N) cin>>x[i]>>y[i]>>c[i];
    K2=2*K;

    vector<vector<int>> B(K2+1,vector<int>(K2+1,0));
    vector<vector<int>> W(K2+1,vector<int>(K2+1,0));
    rep(i,N){
        x[i]=x[i]%K2+1;
        y[i]=y[i]%K2+1;
        if(c[i]=='B') B[x[i]][y[i]]++;
        else W[x[i]][y[i]]++;
    }
    repn(i,K) repn(j,K){
        B[i][j]+=B[i-1][j]+B[i][j-1]-B[i-1][j-1];
        W[i][j]+=W[i-1][j]+W[i][j-1]-W[i-1][j-1];
    }

    int ans=0;
    rep(i,K) rep(j,K){
        int cnt=0;
        cnt+=f(B,i+1,j+1,(i+K-1)%K2+1,(j+K-1)%K2+1);
        cnt+=f(B,(i+K)%K2+1,(j+K)%K2+1,(i-1+K2)%K2+1,(j-1+K2)%K2+1);
        cnt+=f(W,(i+K)%K2+1,j+1,)
    }
    
    return 0;
}