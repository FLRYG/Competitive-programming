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

ll H,W;
char a[1001][1001];

int main(){
    cin>>H>>W;
    repn(i,H) repn(j,W) cin>>a[i][j];

    vector<ll> dp(W,0);
    dp[1]=1;
    repn(i,H){
        repn(j,W){
            if(a[i][j]=='.') dp[j]+=dp[j-1];
            else dp[j]=0;
            dp[j]%=MOD;
        }
    }

    cout<<dp[W]<<endl;
    
    return 0;
}