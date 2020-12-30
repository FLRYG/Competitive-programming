#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <stack>
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
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N,K;
map<P,ll> memo;

ll dfs(ll n, ll k){
    cout<<n<<' '<<k<<endl;
    if(n==1) return 1;
    if(memo[P(n,k)]!=0) return memo[P(n,k)];
    ll res=0;
    rep(i,min(n,k+1)+1){
        res+=dfs(n/2,i)+dfs((n+1)/2,min(n,k+1)-i);
        res%=MOD;
    }
    memo[P(n,k)]=res;
    return res;
}

int main(){
    cin>>N>>K;

    cout<<dfs(N,K)<<endl;
    
    return 0;
}