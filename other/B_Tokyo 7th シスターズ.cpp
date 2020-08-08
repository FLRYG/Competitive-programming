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
#include <bitset>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
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

int N,M;
int A[16];
int B[50];
int C[50];
int I[50][16];

int main(){
    cin>>N>>M;
    rep(i,N) cin>>A[i];
    rep(i,M){
        cin>>B[i]>>C[i];
        rep(j,C[i]) cin>>I[i][j];
    }

    int ans=0;
    rep(i,1<<N){
        int sum=0;
        rep(j,N){
            sum+=i>>j&1;
        }
        if(sum!=9) continue;

        int score=0;
        rep(j,N) if(i>>j&1) score+=A[j];

        rep(j,M){
            int cnt=0;
            rep(k,C[j]){
                cnt+=i>>(I[j][k]-1)&1;
            }
            //cout<<" "<<cnt<<endl;
            if(cnt>=3) score+=B[j];
        }

        //cout<<static_cast<bitset<16>>(i)<<endl;
        //cout<<"  "<<score<<endl;
        ans=max(ans,score);
    }

    cout<<ans<<endl;
}