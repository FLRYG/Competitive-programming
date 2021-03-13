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
ll const MOD=998244353;

ll mpow(ll x,ll n){
    if(n==0) return 1;
    else if(n%2) return x*mpow(x,n-1)%MOD;
    return mpow(x*x%MOD,n/2)%MOD;
}

int H,W,K;

int main(){
    cin>>H>>W>>K;
    vector<vector<char>> C(H+1,vector<char>(W+1,'o'));
    rep(i,K){
        int h,w;
        cin>>h>>w;
        cin>>C[h][w];
    }
    repn(i,H) C[i][0]='X';
    repn(j,W) C[0][j]='X';

    vector<vector<ll>> cnt(H+1,vector<ll>(W+1,0));
    cnt[1][1]=mpow(3,H*W-K-1);
    repn(i,H) repn(j,W){
        if(C[i-1][j]=='D') cnt[i][j]+=cnt[i-1][j];
        else if(C[i-1][j]=='X') cnt[i][j]+=cnt[i-1][j];
        else if(C[i-1][j]=='o') cnt[i][j]+=2*cnt[i-1][j];
        if(C[i][j-1]!='R') cnt[i][j]+=cnt[i][j-1];
        else if(C[i][j-1]!='X') cnt[i][j]+=cnt[i][j-1];
        else if(C[i][j-1]!='o') cnt[i][j]+=2*cnt[i][j-1];
        cnt[i][j]%=MOD;
    }

    cout<<cnt[H][W]<<endl;
    
    return 0;
}