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

int H,W;
char S[500][500];

int main(){
    cin>>H>>W;
    rep(i,H) rep(j,W) cin>>S[i][j];

    ll cnt=0;
    rep(k,H+W-1){
        int r=0, b=0, d=0;
        int j=0;
        for(int i=k;i>=0;i--){
            j=k-i;
            if(0<=i && i<H && 0<=j && j<W){
                // cout<<'('<<i<<','<<j<<')'<<endl;
                if(S[i][j]=='R') r++;
                if(S[i][j]=='B') b++;
                if(S[i][j]=='.') d++;
            }
        }
        if(r>0 && b>0){
            cout<<0<<endl;
            return 0;
        }
        if(r==0 && b==0) cnt++;
    }

    ll ans=mpow(2,cnt);
    cout<<ans<<endl;
    
    return 0;
}