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

int N,M,X;
int C[12];
int A[12][12];

int main(){
    cin>>N>>M>>X;
    rep(i,N){
        cin>>C[i];
        rep(j,M){
            cin>>A[i][j];
        }
    }

    ll ans=1001001001;
    for(ll i=0;i<(1<<N);i++){
        ll price=0;
        vector<ll> a(12,0);
        for(ll j=0;j<N;j++){
            ll s=(i>>j)&1;
            if(s){
                price+=C[j];
                rep(k,M){
                    a[k]+=A[j][k];
                }
            }
        }
        bool ok=true;
        rep(j,M){
            if(a[j]<X) ok=false;
        }
        if(ok) ans=min(ans,price);
    }
    if(ans==1001001001) ans=-1;

    cout<<ans<<endl;
}