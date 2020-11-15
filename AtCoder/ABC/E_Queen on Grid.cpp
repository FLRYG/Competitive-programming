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
typedef pair<ll,ll> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int I[]={0,1,1};
int J[]={1,0,1};

ll H,W;
char S[2001][2001];

int main(){
    cin>>H>>W;
    repn(i,H) repn(j,W) cin>>S[i][j];

    vector<vector<ll>> cnt(H+1,vector<ll>(W+1));
    cnt[1][1]=1;
    vector<vector<ll>> sumh(H+1,vector<ll>(W+1));
    vector<vector<ll>> sumv(H+1,vector<ll>(W+1));
    vector<vector<ll>> sumd(H+1,vector<ll>(W+1));
    sumh[1][1]=1;
    sumv[1][1]=1;
    sumd[1][1]=1;
    vector<vector<bool>> b(H+1,vector<bool>(W+1));
    rep(i,W+1) b[0][i]=true;
    rep(i,H+1) b[i][0]=true;
    repn(i,H) repn(j,W) if(S[i][j]=='#') b[i][j]=true;
    queue<P> q;
    q.push(P(1,1));
    while(!q.empty()){
        P p=q.front(); q.pop();
        ll i=p.first, j=p.second;
        if()
        if(!(b[i-1][j] && b[i-1][j-1] && b[i][j-1])){
            q.push(p);
            continue;
        }
        if(p!=P(1,1)){
            cnt[i][j]=sumh[i][j-1]+sumv[i-1][j]+sumd[i-1][j-1];
            cnt[i][j]%=MOD;
            sumh[i][j]=(sumh[i][j-1]+cnt[i][j])%MOD;
            sumv[i][j]=(sumv[i-1][j]+cnt[i][j])%MOD;
            sumd[i][j]=(sumd[i-1][j-1]+cnt[i][j])%MOD;
        }
        b[i][j]=true;
        rep(k,3){
            ll i=p.first+I[k];
            ll j=p.second+J[k];
            if(1<=i && i<=H && 1<=j && j<=W && S[i][j]=='.'){
                q.push(P(i,j));
            }
        }
    }

    cout<<cnt[H][W]<<endl;

    return 0;
}