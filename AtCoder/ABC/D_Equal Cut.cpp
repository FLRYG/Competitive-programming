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

    ll P=0, Q=0, R=A[1], S=sum[N-1]-sum[2];
    ll i=0,j=2;
    ll ans=LINF;
    for(ll k=2;k<=N-2;k++){
        Q+=A[k-1];
        R-=A[k-1];

        ll d1=abs(sum[k]-2*sum[i]);
        while(i+1<k && abs(sum[k]-2*sum[i+1])<d1){
            d1=abs(sum[k]-2*sum[i+1]);
            P=sum[i+1];
            Q=sum[k]-sum[i+1];
            i++;
        }

        j=max(j,k);
        ll d2=abs(sum[N]+sum[k]-2*sum[j]);
        // cout<<j<<endl;
        // cout<<abs(sum[N]+sum[k]-2*sum[j+1])<<endl;
        while(j+1<N && abs(sum[N]+sum[k]-2*sum[j+1])<d2){
            d2=abs(sum[N]+sum[k]-2*sum[j+1]);
            R=sum[j+1]-sum[k];
            S=sum[N]-sum[j+1];
            j++;
        }
        cout<<i<<' '<<k<<' '<<j<<endl;
        cout<<P<<' '<<Q<<' '<<R<<' '<<S<<endl;
        ans=min(ans,mmax(P,Q,R,S)-mmin(P,Q,R,S));
    }

    // ll P=0, Q=A[0]+A[1], R=A[1], S=sum[N-1]-sum[1];
    // ll i=1,j=3;
    // ll ans=LINF;
    // for(int k=2;k<=N-2;k++){
    //     ll d1=LINF;
    //     ll d2=LINF;
    //     Q+=A[k-1];
    //     R-=A[k-1];
    //     while(i<k && abs((P+A[i-1])-(Q-A[i-1]))<d1){
    //         P+=A[i-1];
    //         Q-=A[i-1];
    //         d1=abs((P+A[i-1])-(Q-A[i-1]));
    //         i++;
    //     }
    //     while(j<N && abs((R+A[j-1])-(S-A[j-1]))<d2){
    //         R+=A[j-1];
    //         S-=A[j-1];
    //         d2=abs((R+A[j-1])-(S-A[j-1]));
    //         j++;
    //     }
    //     cout<<i-1<<' '<<k<<' '<<j-1<<endl;
    //     cout<<P<<' '<<Q<<' '<<R<<' '<<S<<endl;
    //     ans=min(ans,mmax(P,Q,R,S)-mmin(P,Q,R,S));
    // }

    cout<<ans<<endl;
    
    return 0;
}

// #include <iostream>
// #include <stdio.h>
// #include <algorithm>
// #include <cmath>
// #include <string>
// #include <vector>
// #include <iomanip>
// #include <queue>
// #include <deque>
// #include <map>
// #include <unordered_map>
// #define rep(i,n) for(int i=0;i<n;i++)
// #define repn(i,n) for(int i=1;i<=n;i++)
// using namespace std;
// typedef long long ll;

// const ll INF=1001001001001001001;

// ll N;
// ll A[200001];
// ll sum[200001];

// // inline ll f(int i,int j){
// //     return sum[i]-sum[j]; 
// // }

// // int main(){
// //     cin>>N;
// //     repn(i,N) cin>>A[i];

// //     repn(i,N) sum[i]=A[i]+sum[i-1];
// //     //repn(i,N) cout<<sum[i]<<' ';
// //     //cout<<endl;

// //     ll S,Q,R,T;
// //     ll diff1=INF, diff2=INF;
// //     for(int i=2;i<=N-2;i++){
// //         for(int j=1;j<i;j++){
// //             ll s=f(0,j);
// //             ll q=f(j,i);
// //             if(abs(s-q)<diff1){
// //                 S=s;
// //                 Q=q;
// //                 diff1=abs(s-q);
// //             }
// //         }
// //         for(int j=i+1;j<N;j++){
// //             ll r=f(i,j);
// //             ll t=f(j,N);
// //             if(abs(r-t)<diff2){
// //                 R=r;
// //                 T=t;
// //                 diff2=abs(r-t);
// //             }
// //         }
// //     }

// //     ll ans=max(max(S,Q),max(R,T))-min(min(S,Q),min(R,T));
// //     cout<<ans<<endl;
// // }