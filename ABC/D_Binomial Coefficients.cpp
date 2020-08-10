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
//typedef pair<ll,ll> P;
//ll const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

ll n;
ll a[100000];

int main(){
    cin>>n;
    rep(i,n) cin>>a[i];

    ll maxi=0;
    rep(i,n) maxi=max(maxi,a[i]);

    ll r=0;
    rep(i,n){
        if(min(maxi-r,r)<min(maxi-a[i],a[i])) r=a[i];
    } 

    cout<<maxi<<' '<<r<<endl;
}