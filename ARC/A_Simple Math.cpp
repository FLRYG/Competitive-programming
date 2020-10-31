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
ll const MOD=998244353;

ll mpow(ll x,ll n){
    if(n==0) return 1;
    else if(n%2) return x*mpow(x,n-1)%MOD;
    return mpow(x*x%MOD,n/2)%MOD;
}

ll A,B,C;

int main(){
    cin>>A>>B>>C;

    ll ans=1;
    ans*=A;
    ans%=MOD;
    ans*=(A+1);
    ans%=MOD;
    ans*=mpow(2,MOD-2);
    ans%=MOD;

    ans*=B;
    ans%=MOD;
    ans*=(B+1);
    ans%=MOD;
    ans*=mpow(2,MOD-2);
    ans%=MOD;

    ans*=C;
    ans%=MOD;
    ans*=(C+1);
    ans%=MOD;
    ans*=mpow(2,MOD-2);
    ans%=MOD;

    cout<<ans<<endl;
}