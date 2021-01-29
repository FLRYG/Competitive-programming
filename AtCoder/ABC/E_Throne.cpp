#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
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

template<class T>T gcd(T a, T b){return b?gcd(b,a%b):a;}
template<class T>T lcm(T a, T b){return a/gcd(a,b)*b;}

ll mpow(ll x,ll n,ll MOD){
    if(n==0) return 1;
    else if(n%2) return x*mpow(x,n-1,MOD)%MOD;
    return mpow(x*x%MOD,n/2,MOD)%MOD;
}

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}

int T,N,S,K;

int main(){
    cin>>T;

    vector<ll> ans(T);
    rep(i,T){
        cin>>N>>S>>K;
        if(gcd(N,S)==gcd(N,K)){
            ll g=gcd(N,S);
            N/=g;
            S/=g;
            K/=g;
        }
        if(gcd(N,K)==1){
            ans[i]=(N-S)*modinv(K,N)%N;
        }else{
            ans[i]=-1;
        }
    }

    rep(i,T) cout<<ans[i]<<endl;
    
    return 0;
}