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
//ll const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

ll N;
ll a[300000];

int main(){
    cin>>N;
    rep(i,3*N) cin>>a[i];

    sort(a,a+3*N,greater<>());

    ll ans=0;
    rep(i,2*N){
        if(i&1) ans+=a[i];
    }

    cout<<ans<<endl;
}