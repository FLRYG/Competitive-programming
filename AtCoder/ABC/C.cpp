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
    else if(n%2) return x*mpow(x,n-1);
    return mpow(x*x,n/2);
}

ll mfrac(ll n){
    if(n==0) return 1;
    else return n*mfrac(n-1);
}

ll mperm(ll n,ll r){
    ll res=1;
    for(ll i=0;i<r;i++) res=res*(n-i);
    return res;
}

ll mcomb(ll n,ll r){
    if(r>n-r) r=n-r;
    ll res=mperm(n,r);
    res/=mfrac(r);
    return res;
}

ll L;
ll p[201][201];

int main(){
    cin>>L;

    p[0][0]=1;
    repn(n,L){
        p[n][0]=1;
        p[n][n]=1;
        repn(k,n-1) p[n][k]=p[n-1][k-1]+p[n-1][k];
    }
    cout<<p[L-1][11]<<endl;
    
    return 0;
}