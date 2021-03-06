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

ll N;
ll a[3001];
vector<vector<bool>> chk;
vector<vector<ll>> dp;

ll dfs(ll l, ll r){
    // cout<<l<<' '<<r<<endl;
    if(chk[l][r]) return dp[l][r];
    ll res;
    if((N&1)==((r-l+1)&1)){
        if(l==r) res=a[l];
        else res=max(dfs(l,r-1)+a[r],dfs(l+1,r)+a[l]);
    }else{
        if(l==r) res=-a[l];
        else res=min(dfs(l,r-1)-a[r],dfs(l+1,r)-a[l]);
    }
    chk[l][r]=true;
    dp[l][r]=res;
    return res;
}

int main(){
    cin>>N;
    repn(i,N) cin>>a[i];
    chk=vector<vector<bool>>(N+1,vector<bool>(N+1,false));
    dp=vector<vector<ll>>(N+1,vector<ll>(N+1));

    cout<<dfs(1,N)<<endl;
    
    return 0;
}