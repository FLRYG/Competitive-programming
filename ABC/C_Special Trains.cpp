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
//typedef pair<ll,ll> P;
//ll const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

int N;
int C[501];
int S[501];
int F[501];

int main(){
    cin>>N;
    rep(i,N-1) cin>>C[i]>>S[i]>>F[i];

    rep(i,N){
        int ans=S[i];
        rep(j,N-i-1){
            int wait=(F[i+j]-ans%F[i+j])%F[i+j];
            ans+=wait;
            if(ans<S[i+j]) ans=S[i+j];
            ans+=C[i+j];
        }
        cout<<ans<<endl;
    }
}