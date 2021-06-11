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

int N,S;
int A[100], B[100];

int main(){
    cin>>N>>S;
    rep(i,N) cin>>A[i]>>B[i];

    vector<vector<bool>> dp(N+1,vector<bool>(S+1,0));
    dp[0][0]=1;
    rep(i,N) rep(j,S+1){
        if(dp[i][j]){
            if(j+A[i]<=S) dp[i+1][j+A[i]]=1;
            if(j+B[i]<=S) dp[i+1][j+B[i]]=1;
        }
    }

    if(!dp[N][S]){
        cout<<"Impossible"<<endl;
        return 0;
    }

    string ans;
    int c=S;
    for(int i=N-1;i>=0;i--){
        if(c-A[i]>=0 && dp[i][c-A[i]]){
            ans+='A';
            c-=A[i];
        }
        else if(c-B[i]>=0 && dp[i][c-B[i]]){
            ans+='B';
            c-=B[i];
        }
    }
    reverse(ans.begin(),ans.end());

    cout<<ans<<endl;
    
    return 0;
}