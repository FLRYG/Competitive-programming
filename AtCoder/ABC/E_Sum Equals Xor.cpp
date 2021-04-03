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
    else if(n%2) return x*mpow(x,n-1)%MOD;
    return mpow(x*x%MOD,n/2)%MOD;
}

string L;
int N;
vector<ll> comb;

ll f(ll i, bool prev){
    if(prev){
        if(L[i]=='0'){
            return f(i+1,true)%MOD;
        }else{
            return 2*f(i+1,true)%MOD+
        }
    }else{
        return  
    }
}

int main(){
    cin>>L;
    N=L.size();

    ll ans=0;
    comb.resize(N+1);
    comb[0]=1;
    repn(i,N){
        comb[i]*=comb[i-1]*(N-i)%MOD*mpow(i,MOD-2)%MOD;
        comb[i]%=MOD;
    }

    ll ans=f(0,true,0);
    
    return 0;
}