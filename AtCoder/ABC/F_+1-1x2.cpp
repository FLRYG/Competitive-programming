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

ll X,Y;
map<ll,ll> memo;

ll dfs(ll x, ll y){
    if(x==y) return 0;
    if(y<x) return x-y;
    if(memo[y]!=0) return memo[y];
    ll res=y-x;
    if(!(y&1)) res=min(res,dfs(x,y/2)+1);
    else{
        res=min(res,dfs(x,y-1)+1);
        res=min(res,dfs(x,y+1)+1);
    }
    memo[y]=res;
    return res;
}

int main(){
    cin>>X>>Y;

    cout<<dfs(X,Y)<<endl;
    
    return 0;
}