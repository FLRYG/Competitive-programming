#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

const int MOD=1'000'000'007;
int N,M;
int a[100001];
int dp[100001];

int main(){
    cin>>N>>M;
    rep(i,M){
        int x;
        cin>>x;
        a[x]=1;
    }

    dp[0]=1;
    dp[1]=1;
    if(a[1]==1) dp[1]=0;
    for(int i=2;i<=N;i++){
        dp[i]=(dp[i-2]+dp[i-1])%MOD;
        if(a[i]==1) dp[i]=0;
    }

    cout<<dp[N]<<endl;
}