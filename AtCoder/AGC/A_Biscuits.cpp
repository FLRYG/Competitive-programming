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

ll N,P;
ll A[50];

ll pow(ll x,ll n){
    if(n==0) return 1;
    else if(n%2) return x*pow(x,n-1);
    return pow(x*x,n/2);
}

ll pcomb(ll n, ll r){
    vector<vector<ll>> v(n+1,vector<ll>(n+1,0));
    for(int i = 0;i <v.size(); i++){
        v[i][0]=1;
        v[i][i]=1;
    }
    for(int k = 1;k <v.size();k++){
        for(int j = 1;j<k;j++){
            v[k][j]=(v[k-1][j-1]+v[k-1][j]);
        }
    }
    return v[n][r];
}

int main(){
    cin>>N>>P;
    rep(i,N) cin>>A[i];
    rep(i,N) A[i]%=2;

    ll even=0, odd=0;
    rep(i,N){
        if(A[i]==0) even++;
        else odd++;
    }

    ll ans=0;
    if(P==0){
        for(int i=0;i<=odd;i+=2){
            ans+=pcomb(odd,i);
        }
        ans*=pow(2,even);
    }else{
        for(int i=1;i<=odd;i+=2){
            ans+=pcomb(odd,i);
        }
        ans*=pow(2,even);
    }

    cout<<ans<<endl;
}