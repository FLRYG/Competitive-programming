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
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N,K;
ll a[15];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>a[i];

    ll ans=LINF;
    rep(n,1<<(N-1)){
        ll cnt=0;
        rep(i,N-1) cnt+=n>>i&1;
        if(cnt!=K-1) continue;

        ll sup=a[0];
        ll res=0;
        rep(i,N-1){
            if(n>>i&1){
                if(a[i+1]<=sup){
                    sup++;
                    res+=sup-a[i+1];
                }else{
                    sup=a[i+1];
                }
            }else{
                sup=max(sup,a[i+1]);
            }
        }
        //cout<<' '<<res<<endl;
        ans=min(ans,res);
    }

    cout<<ans<<endl;
}