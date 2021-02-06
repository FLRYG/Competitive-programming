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

int N,K;
int a[100000];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>a[i];

    vector<bool> dp(K+1,false);
    rep(i,K+1){
        bool b=false;
        rep(j,N){
            if(i<a[j]) break;
            b|=!dp[i-a[j]];
        }
        dp[i]=b;
    }

    string ans="Second";
    if(dp[K]) ans="First";

    cout<<ans<<endl;
    
    return 0;
}