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
int A[400];
int memo[400][400];

int dfs(int l, int r){
    if(memo[l][r]!=INF) return memo[l][r];
    if(l+1==r) return memo[l][r]=abs(A[l]-A[r]);
    int res=abs(A[l]-A[r])+dfs(l+1,r-1);
    for(int i=l+1;i<r;i+=2){
        res=min(res,dfs(l,i)+dfs(i+1,r));
    }
    return memo[l][r]=res;
}

int main(){
    cin>>N;
    rep(i,2*N) cin>>A[i];

    rep(i,2*N) rep(j,2*N) memo[i][j]=INF;    
    int ans=dfs(0,2*N-1);

    cout<<ans<<endl;
    
    return 0;
}