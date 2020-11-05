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

int N;
int a[100001], b[100001], c[100001];
int dp[100001][3];

int main(){
    cin>>N;
    repn(i,N) cin>>a[i]>>b[i]>>c[i];

    repn(i,N){
        dp[i][0]=max(dp[i-1][1],dp[i-1][2])+a[i];
        dp[i][1]=max(dp[i-1][2],dp[i-1][0])+b[i];
        dp[i][2]=max(dp[i-1][0],dp[i-1][1])+c[i];
    }

    int ans=max(max(dp[N][0],dp[N][1]),dp[N][2]);
    cout<<ans<<endl;
}