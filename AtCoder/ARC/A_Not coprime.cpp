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

template<class T>T gcd(T a, T b){return b?gcd(b,a%b):a;}
template<class T>T lcm(T a, T b){return a/gcd(a,b)*b;}

bool prime(int x){
    bool res=true;
    for(int i=2;i<x;i++) res&=(x%i!=0);
    return res;
}

ll N;
ll X[50];
ll p[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

int main(){
    cin>>N;
    rep(i,N) cin>>X[i];

    vector<vector<int>> v(15,vector<int>(N,0));
    int id=0;
    for(ll i=2;i<=50;i++){
        if(!prime(i)) continue;
        // cout<<i<<endl;
        rep(j,N){
            if(X[j]%i==0) v[id][j]=1;
        }
        id++;
    }
    // rep(i,15){
    //     cout<<p[i]<<' ';
    //     rep(j,N) cout<<v[i][j]<<' ';
    //     cout<<endl;
    // }

    ll ans=8*LINF;
    rep(i,1<<15){
        vector<int> vv(N,0);
        rep(j,15){
            if(i>>j&1){
                rep(k,N) vv[k]|=v[j][k];
            }
        }
        int f=1;
        rep(j,N) f&=vv[j];
        if(f){
            ll res=1;
            rep(j,15) if(i>>j&1) res*=p[j];
            // cout<<res<<endl;
            ans=min(ans,res);
        }
    }

    cout<<ans<<endl;

    // ll g=0;
    // rep(i,N)

    // vector<bool> chk(N,false);

    // ll ans=1;
    // for(int i=2;i<=100;i++){
    //     bool b=false;
    //     rep(j,N){
    //         if(chk[j]) continue;
    //         if(X[j]%i==0){
    //             chk[j]=true;
    //             b=true;
    //         }
    //     }
    //     if(b) ans*=i;
    //     bool f=true;
    //     rep(j,N) f&=chk[j];
    //     if(f) break;
    // }

    // cout<<ans<<endl;

    // sort(X,X+N);

    // set<ll> s;
    // rep(i,N){
    //     ll x=X[i];
    //     set<ll> ss;
    //     for(ll j=2;j<=50;j++){
    //         if(x%j==0){
    //             ss.insert(j);
    //             while(x%j==0) x/=j;
    //         }
    //     }
    //     bool b=true;
    //     repr(e,ss){
    //         b&=s.find(e)==s.end();
    //     }
    //     if(b) repr(e,ss) s.insert(e);
    // }

    // ll ans=1;
    // repr(e,s) ans*=e;

    // cout<<ans<<endl;
    
    return 0;
}