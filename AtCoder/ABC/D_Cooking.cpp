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

int N;
int T[101];

int main(){
    cin>>N;
    repn(i,N) cin>>T[i];

    // vector<int> dp(100001,0);
    // dp[0]=1;
    // repn(i,N){
    //     vector<int> v(100001,0);
    //     rep(j,100001){
    //         v[j]=dp[j];
    //         if(j>=T[i]) v[j]|=dp[j-T[i]];
    //         dp=v;
    //     }
    // }

    set<int> dp;
    dp.insert(0);
    repn(i,N){
        set<int> s=dp;
        repr(e,dp){
            s.insert(e+T[i]);
        }
        dp=s;
    }

    int sum=0;
    repn(i,N) sum+=T[i];

    int ans=INF;
    repr(e,dp){
        ans=min(ans,max(sum-e,e));
        // cout<<e<<endl;
    }

    cout<<ans<<endl;
    
    return 0;
}