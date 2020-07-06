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

ll N,H;
ll a[100000], b[100000];

int main(){
    cin>>N>>H;
    rep(i,N) cin>>a[i]>>b[i];

    ll amax=0;
    rep(i,N) amax=max(amax,a[i]);

    vector<ll> x;
    rep(i,N){
        if(b[i]>amax) x.push_back(b[i]);
    }
    sort(x.begin(),x.end(),greater<ll>());

    ll ans=0;
    rep(i,(int)x.size()){
        H-=x[i];
        ans++;
        if(H<=0){
            cout<<ans<<endl;
            return 0;
        }
    }

    ans+=(H-1)/amax+1;

    cout<<ans<<endl;
}