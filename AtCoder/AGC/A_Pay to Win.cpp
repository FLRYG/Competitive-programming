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
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int T;

ll dfs(ll N, ll A, ll B, ll C, ll D, map<ll,ll> memo){
    cout<<N<<endl;
    if(N==0) return LINF;
    if(N==1) return D;
    if(memo[N]!=0) return memo[N];
    ll res=LINF;
    res=min(res,dfs(N/2,A,B,C,D,memo)+A+D*(N-N/2*2));
    res=min(res,dfs(N/2+1,A,B,C,D,memo)+A+D*((N/2+1)*2-N));
    res=min(res,dfs(N/3,A,B,C,D,memo)+B+D*(N-N/3*3));
    res=min(res,dfs(N/3+1,A,B,C,D,memo)+B+D*((N/3+1)*3-N));
    res=min(res,dfs(N/5,A,B,C,D,memo)+C+D*(N-N/5*5));
    res=min(res,dfs(N/5+1,A,B,C,D,memo)+C+D*((N/5+1)*5-N));
    memo[N]=res;
    cout<<' '<<N<<' '<<res<<endl;
    return res;
}

int main(){
    cin>>T;

    vector<ll> ans(T);
    rep(t,T){
        ll N,A,B,C,D;
        cin>>N>>A>>B>>C>>D;
        map<ll,ll> memo;

        ans[t]=dfs(N,A,B,C,D,memo);
    }

    rep(i,T) cout<<ans[i]<<endl;
    
    return 0;
}