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

ll N,K;
ll a[100001];

int main(){
    cin>>N>>K;
    repn(i,N) cin>>a[i];

    repn(i,N) a[i]+=a[i-1];

    ll ans=0;
    for(int i=K;i<=N;i++){
        ans+=a[i]-a[i-K];
    }

    cout<<ans<<endl;
}