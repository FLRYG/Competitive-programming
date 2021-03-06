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

ll L,R;

int main(){
    cin>>L>>R;

    ll ten=1, digit=1, ans=0, inv2=mpow(2,MOD-2);
    rep(i,18){
        ll l=max(ten,L)-1;
        ll r=min(ten*10-1,R);
        if(l<r){
            l%=MOD;
            r%=MOD;
            ans+=digit*r%MOD*(r+1)%MOD*inv2%MOD;
            ans%=MOD;
            ans-=digit*l%MOD*(l+1)%MOD*inv2%MOD;
            ans%=MOD;
        }
        ten*=10;
        digit++;
    }
    if(R==1'000'000'000'000'000'000){
        ans+=1'000'000'000'000'000'000%MOD*19%MOD;
        ans%=MOD;
    }
    if(ans<0) ans+=MOD;

    cout<<ans<<endl;
    
    return 0;
}