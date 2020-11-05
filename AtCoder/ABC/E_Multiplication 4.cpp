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
typedef pair<ll,pair<ll,ll>> PP;

const ll MOD=1'000'000'007;

ll N,K;
ll A[200001];
ll zero;
PP dp[200001];

int main(){
    cin>>N>>K;
    repn(i,N){
        cin>>A[i];
        if(A[i]==0) zero++;
    }
    if(K>N-zero){
        cout<<0<<endl;
        return 0;
    }
    sort(A+1,A+N+1);
    repn(i,N)cout<<A[i]<<' ';cout<<endl;

    dp[0]=PP(1,P(1,N));
    dp[1]=PP(A[N],P(1,N-1));
    for(int i=2;i<=N;i++){
        ll x_2=dp[i-2].first;
        ll x_1=dp[i-1].first;
        ll v_2=x_2*A[dp[i-2].second.first]*A[dp[i-2].second.first+1];
        ll v_1=x_1*A[dp[i-1].second.second];
        if(v_2>=v_1){
            dp[i]=PP(v_2,P(dp[i-2].second.first+2,dp[i-2].second.second));
        }else{
            dp[i]=PP(v_1,P(dp[i-1].second.first,dp[i-1].second.second-1));
        }
        dp[i].first%=MOD;
    }

    rep(i,K) cout<<dp[i].first<<endl;
    cout<<dp[K].first<<endl;
}