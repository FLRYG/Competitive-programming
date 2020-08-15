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
//ll const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

ll N;
ll C[200001];
ll dp[200001];
ll cnt[200001];
ll last[200001];

int main(){
    cin>>N;
    repn(i,N) cin>>C[i];

    dp[0]=1;
    ll prev=-1;
    repn(i,N){
        dp[i]=dp[i-1];
        if(prev!=C[i]){
            cnt[C[i]]++;
            if(cnt[C[i]]>=2){
                dp[i]+=dp[last[C[i]]];
            }
            dp[i]%=MOD;
        }
        last[C[i]]=i;
        prev=C[i];
    }
    //repn(i,N) cout<<"i:"<<i<<" "<<dp[i]<<endl;

    cout<<dp[N]<<endl;
}