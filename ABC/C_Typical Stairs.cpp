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

ll N,M;
ll s[100001];
ll dp[100001];

int main(){
    cin>>N>>M;
    rep(i,M){
        ll a;
        cin>>a;
        s[a]++;
    }

    dp[0]=1;
    if(s[1]!=1) dp[1]=1;
    for(int i=2;i<=N;i++){
        if(s[i]!=1) dp[i]=dp[i-1]+dp[i-2];
        dp[i]%=MOD;
    }

    cout<<dp[N]<<endl;
}


/*
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
*/