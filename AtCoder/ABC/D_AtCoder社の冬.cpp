#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <chrono>
#include <random>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
// typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll mpow(ll x,ll n){
    if(n==0) return 1;
    else if(n%2) return x*mpow(x,n-1)%MOD;
    return mpow(x*x%MOD,n/2)%MOD;
}

ll mfrac(ll n){
    if(n==0) return 1;
    else return n*mfrac(n-1)%MOD;
}

ll mperm(ll n,ll r){
    ll res=1;
    for(ll i=0;i<r;i++) res=res*(n-i)%MOD;
    return res;
}

ll mcomb(ll n,ll r){
    if(r>n-r) r=n-r;
    ll res=mperm(n,r);
    return res*mpow(mfrac(r),MOD-2)%MOD;
}

ll R,C,X,Y,D,L;

int main(){
    cin>>R>>C>>X>>Y>>D>>L;

    vector<vector<ll>> cnt(X+1,vector<ll>(Y+1,0));
    repn(x,X){
        repn(y,Y){
            if(x*y<D+L) continue;
            cnt[x][y]=mcomb(x*y,D)*mcomb(x*y-D,L)%MOD;
            ll sum=0;
            repn(i,x){
                repn(j,y){
                    if(i==x && j==y) continue;
                    sum+=(x-i+1)*(y-j+1)*cnt[i][j]%MOD;
                    sum%=MOD;
                }
            }
            cnt[x][y]-=sum;
            cnt[x][y]%=MOD;
        }
    }

    ll ans=(R-X+1)*(C-Y+1)%MOD*cnt[X][Y]%MOD;
    if(ans<0) ans+=MOD;

    cout<<ans<<endl;
    
    return 0;
}



// 部分点 
// ll R,C,X,Y,D,L;

// int main(){
//     cin>>R>>C>>X>>Y>>D>>L;

//     ll ans=1;
//     rep(i,D){
//         ans*=D+L-i;
//         ans%=MOD;
//         ans*=mpow(i+1,MOD-2);
//         ans%=MOD;
//     }
//     ans*=(R-X+1)*(C-Y+1)%MOD;
//     ans%=MOD;

//     cout<<ans<<endl;
    
//     return 0;
// }