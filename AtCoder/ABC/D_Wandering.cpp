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

ll N;
ll A[200000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    vector<ll> sum(N,0);
    vector<ll> t(N,0);
    rep(i,N) sum[i]=A[i];
    rep(i,N-1) sum[i+1]+=sum[i];
    //rep(i,N) cout<<sum[i]<<' ';cout<<endl;
    rep(i,N) t[i]=sum[i];
    rep(i,N-1) sum[i+1]=max(sum[i+1],sum[i]);

    rep(i,N-1) t[i+1]+=t[i];
    //rep(i,N) cout<<sum[i]<<' ';cout<<endl;

    ll ans=0;
    rep(i,N-1){
        ans=max(ans,t[i]+sum[i+1]);
    }
    ans=max(ans,t[0]);

    // ll maxi=-INF;
    // ll idx=0;
    // rep(i,N){
    //     if(t[i]>maxi){
    //         maxi=t[i];
    //         idx=i;
    //     }
    // }

    cout<<ans<<endl;
    
    return 0;
}