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
ll A,B,C,D;
map<ll,ll> memo;

ll dfs(ll N){
    //cout<<N<<endl;
    if(N==0) return 0;
    if(N==1) return D;
    if(memo[N]!=0) return memo[N];
    ll res=LINF;
    if(N<res/D) res=N*D;
    res=min(res,dfs(N/2)+A+D*(N-N/2*2));
    res=min(res,dfs((N+1)/2)+A+D*(((N+1)/2)*2-N));
    res=min(res,dfs(N/3)+B+D*(N-N/3*3));
    res=min(res,dfs((N+2)/3)+B+D*(((N+2)/3)*3-N));
    res=min(res,dfs(N/5)+C+D*(N-N/5*5));
    res=min(res,dfs((N+4)/5)+C+D*(((N+4)/5)*5-N));
    memo[N]=res;
    //cout<<' '<<N<<' '<<res<<endl;
    return res;
}

int main(){
    cin>>T;

    vector<ll> ans(T);
    rep(t,T){
        ll N;
        cin>>N>>A>>B>>C>>D;
        memo.clear();

        ans[t]=dfs(N);
    }

    rep(i,T) cout<<ans[i]<<endl;
    
    return 0;
}