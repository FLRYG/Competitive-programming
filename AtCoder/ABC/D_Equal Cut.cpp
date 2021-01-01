#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <stack>
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
ll A[200001];

inline ll mmax(ll a, ll b, ll c, ll d){
    return max(max(a,b),max(c,d));
}

inline ll mmin(ll a, ll b, ll c, ll d){
    return min(min(a,b),min(c,d));
}

int main(){
    cin>>N;
    repn(i,N) cin>>A[i];

    vector<ll> sum(N+1,0);
    repn(i,N) sum[i]=sum[i-1]+A[i];

    ll P,Q,R,S;
    ll i=1,j=3;
    ll ans=LINF;
    for(ll k=2;k<=N-2;k++){
        P=sum[i];
        Q=sum[k]-P;
        ll d1=abs(sum[k]-2*P);
        while(i+1<k && abs(sum[k]-2*(P+A[i+1]))<d1){
            d1=abs(sum[k]-2*(P+A[i+1]));
            P+=A[i+1];
            Q-=A[i+1];
            i++;
        }

        j=max(j,k);
        R=sum[j]-sum[k];
        S=sum[N]-sum[k]-R;
        ll d2=abs(sum[N]-sum[k]-2*R);
        // cout<<j<<endl;
        // cout<<abs(sum[N]+sum[k]-2*sum[j+1])<<endl;
        while(j+1<N && abs(sum[N]-sum[k]-2*(R+A[j+1]))<d2){
            d2=abs(sum[N]-sum[k]-2*(R+A[j+1]));
            R+=A[j+1];
            S-=A[j+1];
            j++;
        }
        // cout<<i<<' '<<k<<' '<<j<<endl;
        // cout<<P<<' '<<Q<<' '<<R<<' '<<S<<endl;
        ans=min(ans,mmax(P,Q,R,S)-mmin(P,Q,R,S));
    }

    cout<<ans<<endl;
    
    return 0;
}