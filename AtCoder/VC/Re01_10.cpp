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
// typedef pair<int,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
string S;

int main(){
    cin>>N>>S;

    int ans=0;
    string a="", b=S;
    rep(i,N-1){
        a+=S[i];
        b.erase(b.begin());
        vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,0));
        repn(j,a.size()){
            repn(k,b.size()){
                if(a[j-1]==b[k-1]) dp[j][k]=dp[j-1][k-1]+1;
                dp[j][k]=max(dp[j][k],max(dp[j-1][k],dp[j][k-1]));
            }
        }
        // cout<<a<<' '<<b<<' '<<dp[a.size()][b.size()]<<endl;
        ans=max(ans,dp[a.size()][b.size()]);
    }

    ans=N-2*ans;
    cout<<ans<<endl;
    
    return 0;
}