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

ll K;

int main(){
    cin>>K;

    if(K%9!=0){
        cout<<0<<endl;
        return 0;
    }

    vector<ll> dp(K+1,0);
    dp[0]=1;
    repn(i,K){
        repn(j,min(i,9)){
            dp[i]+=dp[i-j];
            dp[i]%=MOD;
        }
    }

    cout<<dp[K]<<endl;
    
    return 0;
}