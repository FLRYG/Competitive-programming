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
char c[100000];
int K2;

int f(vector<vector<int>> &G, int a, int b, int c, int d){
    return G[c-1][d-1]-G[a-1][d-1]-G[c-1][b-1]+G[a-1][b-1];
}

int main(){
    cin>>N>>K;
    rep(i,N) cin>>x[i]>>y[i]>>c[i];
    K2=2*K;

    vector<vector<int>> B(3*K+1,vector<int>(3*K+1,0));
    vector<vector<int>> W(3*K+1,vector<int>(3*K+1,0));
    rep(i,N){
        x[i]=x[i]%K2+1;
        y[i]=y[i]%K2+1;
        if(c[i]=='B') B[x[i]][y[i]]++;
        else W[x[i]][y[i]]++;
    }
    repn(i,K) repn(j,K){
        B[i+K2][j+K2]=B[i][j];
        W[i+K2][j+K2]=W[i][j];
    }
    repn(i,K) repn(j,K2){
        B[i+K2][j]=B[i][j];
        W[i+K2][j]=W[i][j];
    }
    repn(i,K2) repn(j,K){
        B[i][j+K2]=B[i][j];
        W[i][j+K2]=W[i][j];
    }
    repn(i,3*K) repn(j,3*K){
        B[i][j]+=B[i-1][j]+B[i][j-1]-B[i-1][j-1];
        W[i][j]+=W[i-1][j]+W[i][j-1]-W[i-1][j-1];
    }

    int ans=0;
    repn(i,K) repn(j,K){
        int cnt=0;
        cnt+=f(B,i,j,i+K,j+K);
        cnt+=f(B,i+K,j+K,i+K2,j+K2);
        cnt+=f(W,i+K,j,i+K2,j+K);
        cnt+=f(W,i,j+K,i+K,j+K2);
        ans=max(ans,cnt);
        cnt=0;
        cnt+=f(W,i,j,i+K,j+K);
        cnt+=f(W,i+K,j+K,i+K2,j+K2);
        cnt+=f(B,i+K,j,i+K2,j+K);
        cnt+=f(B,i,j+K,i+K,j+K2);
        ans=max(ans,cnt);
    }

    cout<<ans<<endl;
    
    return 0;
}