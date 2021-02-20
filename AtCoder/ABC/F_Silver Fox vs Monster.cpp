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
typedef pair<ll,ll> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N,D,A;

int main(){
    cin>>N>>D>>A;
    vector<P> XH(N+1);
    repn(i,N) cin>>XH[i].first>>XH[i].second;
    XH.push_back(P(LINF,0));
    sort(XH.begin(),XH.end());

    ll ans=0;
    vector<ll> dam(N+2,0);
    repn(i,N){
        dam[i]+=dam[i-1];
        XH[i].second-=dam[i];
        if(XH[i].second>0){
            ll cnt=(XH[i].second+A-1)/A;
            ans+=cnt;
            dam[i]+=A*cnt;
            ll d=XH[i].first+2*D;
            ll l=0,r=N+1;
            while(r-l>1){
                ll m=(l+r)/2;
                if(d<XH[m].first) r=m;
                else l=m;
            }
            dam[r]-=A*cnt;
        }
    }

    cout<<ans<<endl;

    return 0;
}