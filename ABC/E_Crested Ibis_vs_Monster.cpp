#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int H,N;
int A[1000];
int B[1000];
int dp[10001];

int main(){
    cin>>H>>N;
    rep(i,N) cin>>A[i]>>B[i];

    repn(i,H){
        int res=1001001001;
        rep(j,N){
            if(i<=A[j]) res=min(res,B[j]);
            else res=min(res,dp[i-A[j]]+B[j]); 
        }
        dp[i]=res;
        //cout<<i<<":"<<dp[i]<<endl;
    }

    int ans=dp[H];
    cout<<ans<<endl;
}