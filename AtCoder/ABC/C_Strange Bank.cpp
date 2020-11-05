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

int N;
int dp[100001];

int main(){
    cin>>N;

    repn(i,N){
        int x6=6, x9=9;
        dp[i]=1+dp[i-1];
        while(i-x6>=0){
            dp[i]=min(dp[i],1+dp[i-x6]);
            x6*=6;
        }
        while(i-x9>=0){
            dp[i]=min(dp[i],1+dp[i-x9]);
            x9*=9;
        }
    }

    cout<<dp[N]<<endl;
}