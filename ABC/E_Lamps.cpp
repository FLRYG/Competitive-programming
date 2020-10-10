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
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll mpow(ll x,ll n){
    if(n==0) return 1;
    else if(n%2) return x*mpow(x,n-1)%MOD;
    return mpow(x*x%MOD,n/2)%MOD;
}

int I[]={1,0,-1,0};
int J[]={0,1,0,-1};

ll H,W;
string S[2000];
ll cnt[2000][2000];

int main(){
    cin>>H>>W;
    rep(i,H) cin>>S[i];

    ll K=0;
    rep(i,H){
        rep(j,W){
            if(S[i][j]=='#') continue;
            cnt[i][j]++;
            K++;
            rep(k,4){
                repn(l,4){
                    ll x=i+l*I[k];
                    ll y=j+l*J[k];
                    if(0<=x && x<H && 0<=y && y<W && S[x][y]=='.') cnt[x][y]++;
                    else break;
                }
            }
        }
    }
    rep(i,H){rep(j,W){cout<<cnt[i][j]<<' ';}cout<<endl;}

    ll ans=0;
    ll K2=mpow(2,K);
    rep(i,H){
        rep(j,W){
            ans+=K2-mpow(2,K-cnt[i][j]);
            ans%=MOD;
        }
    }

    cout<<ans<<endl;
}