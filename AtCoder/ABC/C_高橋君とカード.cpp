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

ll mpow(ll x,ll n){
    if(n==0) return 1;
    else if(n%2) return x*mpow(x,n-1);
    return mpow(x*x,n/2);
}

int N,A;
int x[50];

int main(){
    cin>>N>>A;
    rep(i,N) cin>>x[i];

    ll zero=0;
    vector<ll> pos(50,0), neg(50,0); 
    rep(i,N){
        x[i]-=A;
        if(x[i]==0) zero++;
        else if(x[i]>0) pos[x[i]]++;
        else neg[-x[i]]++;
    }

    vector<vector<ll>> v(N+1,vector<ll>(N+1,-1));
    for(int i = 0;i <v.size(); i++){
        v[i][0]=1;
        v[i][i]=1;
    }
    for(int k = 1;k <v.size();k++){
        for(int j = 1;j<k;j++){
            v[k][j]=(v[k-1][j-1]+v[k-1][j]);
        }
    }

    vector<vector<ll>> dppos(50,vector<ll>(2501,0));
    vector<vector<ll>> dpneg(50,vector<ll>(2501,0));
    dppos[0][0]=1;
    dpneg[0][0]=1;
    repn(i,49){
        rep(j,2501){
            for(ll k=0;k<=pos[i]&&i*k<=j;k++){
                dppos[i][j]+=dppos[i-1][j-i*k]*v[pos[i]][k];
            }
            for(ll k=0;k<=neg[i]&&i*k<=j;k++){
                dpneg[i][j]+=dpneg[i-1][j-i*k]*v[neg[i]][k];
            }
        }
    }
    // rep(i,50){cout<<i<<' '; rep(j,12) cout<<dppos[i][j]<<' '; cout<<endl;}cout<<endl;
    // rep(i,50){cout<<i<<' '; rep(j,12) cout<<dpneg[i][j]<<' '; cout<<endl;}cout<<endl;

    ll ans=0;
    rep(j,2501) ans+=dppos[49][j]*dpneg[49][j];
    ans*=mpow(2,zero);
    ans--;

    cout<<ans<<endl;
    
    return 0;
}