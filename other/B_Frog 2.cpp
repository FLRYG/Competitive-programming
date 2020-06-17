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

int N,K;
int h[100001];
int dp[100001];

int main(){
    cin>>N>>K;
    repn(i,N) cin>>h[i];

    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<=N;i++){
        int res=1001001001;
        repn(j,min(K,i-1)){
            res=min(res,dp[i-j]+abs(h[i]-h[i-j]));
        }
        dp[i]=res;
    }

    cout<<dp[N]<<endl;
} 