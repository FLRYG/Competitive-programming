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
//typedef pair<int,int> P;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
string S;

int main(){
    cin>>N>>S;

    int ans=N;
    int dp[101][101];
    repn(n,N-1){
        string s,t;
        for(int i=0;i<n;i++) s+=S[i];
        for(int i=n;i<N;i++) t+=S[i];
        rep(i,s.size()+1) dp[i][0]=0;
        rep(j,t.size()+1) dp[0][j]=0;
        repn(i,s.size()){
            repn(j,t.size()){
                if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int res=dp[s.size()][t.size()];
        ans=min(ans,N-2*res);
    }

    cout<<ans<<endl;
}