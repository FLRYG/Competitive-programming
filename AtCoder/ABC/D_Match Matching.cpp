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

string max(string &x, string &y){
    if(x.size()>y.size()) return x;
    if(x.size()<y.size()) return y;
    for(int i=x.size()-1;i>=0;i--){
        if(x[i]>y[i]) return x;
        if(x[i]<y[i]) return y;
    }
    return x;
}

int N,M;
int A[9];
int cost[10]={0,2,5,5,4,5,6,3,7,6};

int main(){
    cin>>N>>M;
    rep(i,M) cin>>A[i];

    vector<string> dp(N+1,"#");
    dp[0]="";
    repn(i,N) rep(j,M){
        if(i-cost[A[j]]>=0 && dp[i-cost[A[j]]]!="#"){
            string s=dp[i-cost[A[j]]];
            s+=A[j]+'0';
            dp[i]=max(dp[i],s);
        }
    }
    // repn(i,N) cout<<i<<' '<<dp[i]<<endl;
    reverse(dp[N].begin(),dp[N].end());

    cout<<dp[N]<<endl;
    
    return 0;
}