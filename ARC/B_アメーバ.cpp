#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
ll const MOD=1'000'000'007;

int x[4]={1,0,-1,0};
int y[4]={0,1,0,-1};

int N,M;
char b[500][500];
int ans[500][500];

int main(){
    cin>>N>>M;
    rep(i,N) rep(j,M) cin>>b[i][j];

    rep(i,N){
        if(i==0 || i==N-1) continue;
        rep(j,M){
            if(j==0 || j==M-1) continue;
            int mini=1001001001;
            rep(k,4) mini=min(mini,(int)(b[i+x[k]][j+y[k]]-'0'));
            rep(k,4) b[i+x[k]][j+y[k]]-=mini;
            ans[i][j]+=mini;
        }
    }

    rep(i,N){
        rep(j,M){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}