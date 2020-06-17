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
int h[100001];
int dp[100001];

int main(){
    cin>>N;
    repn(i,N) cin>>h[i];

    h[0]=1001001001;
    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<=N;i++){
        int a=dp[i-1]+abs(h[i]-h[i-1]);
        int b=dp[i-2]+abs(h[i]-h[i-2]);
        dp[i]=min(a,b);
    }

    cout<<dp[N]<<endl;
}