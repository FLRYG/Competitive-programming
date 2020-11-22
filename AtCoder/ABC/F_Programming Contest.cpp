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

ll N,T;
ll A[40];

ll n,m;
ll a[20];
ll b[20];

int main(){
    cin>>N>>T;
    rep(i,N) cin>>A[i];

    n=N/2;
    m=(N+1)/2;
    rep(i,n) a[i]=A[i];
    rep(i,m) b[i]=A[n+i];

    vector<ll> resa;
    vector<ll> resb;
    rep(i,1<<n){
        ll sum=0;
        rep(j,n){
            ll p=i>>j&1;
            if(p) sum+=a[j];
        }
        resa.push_back(sum);
    }
    rep(i,1<<m){
        ll sum=0;
        rep(j,m){
            ll p=i>>j&1;
            if(p) sum+=b[j];
        }
        resb.push_back(sum);
    }

    sort(resa.begin(),resa.end(),greater<ll>());
    sort(resb.begin(),resb.end());

    // repr(e,resa) cout<<e<<' ';cout<<endl;
    // repr(e,resb) cout<<e<<' ';cout<<endl;

    ll ans=0;
    ll j=0;
    rep(i,resa.size()){
        while(resa[i]+resb[j]<=T && j<resb.size()) j++;
        //cout<<resa[i]<<' '<<resb[j-1]<<endl;
        if(resa[i]+resb[j-1]<=T) ans=max(ans,resa[i]+resb[j-1]);
    }

    cout<<ans<<endl;
    
    return 0;
}