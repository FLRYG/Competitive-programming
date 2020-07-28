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
ll const MOD=1'000'000'007;

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
    if(r>n) return 0;
    if(r>n-r) r=n-r;
    ll res=mperm(n,r);
    return res/mfrac(r);
}

string N;
ll K;
ll dp[4][105];

int main(){
    cout<<("12"<"1")<<endl;
    cin>>N>>K;

    ll ans=mcomb(N.size()-1,K)*mpow(9,K)+(N[0]-'0'-1)*mcomb(N.size()-1,K-1)*mpow(9,K-1);
    cout<<ans<<endl;
    repn(i,N.size()-1){
        dp[1][i]=dp[1][i-1]+(N[N.size()-i]-'0');
        dp[2][i]=dp[1][i-1]*(N[N.size()-i]-'0');
        dp[3][i]=dp[2][i-1]*(N[N.size()-i]-'0');
    }
    if(K==1){
        ans+=dp[K-1][N.size()-1]+1;
    }else{
        ans+=dp[K-1][N.size()-1]*1;
    }

    cout<<ans<<endl;
}