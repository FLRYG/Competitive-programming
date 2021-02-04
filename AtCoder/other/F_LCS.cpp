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

string s,t;

// 正攻法
int main(){
    cin>>s>>t;
    int N,M;
    N=s.size();
    M=t.size();

    vector<vector<int>> dp(N+1,vector<int>(M+1,0));
    rep(i,N){
        rep(j,M){
            if(s[i]==t[j]) dp[i+1][j+1]=dp[i][j]+1;
            else dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
        }
    }
    // cout<<dp[N][M]<<endl;

    string ans;
    int i=N, j=M;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans+=s[i-1];
            i--, j--;
        }else{
            if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
    }
    reverse(ans.begin(),ans.end());

    cout<<ans<<endl;

    return 0;
}


// stringによるゴリ押し
// int main(){
//     cin>>s>>t;
//     int N,M;
//     N=s.size();
//     M=t.size();

//     vector<string> dp(M+2,"");
//     string tmp1,tmp2;
//     rep(i,N){
//         tmp1=dp[0];
//         tmp2=dp[1];
//         rep(j,M){
//             if(s[i]==t[j]) dp[j+1]=tmp1+s[i];
//             else if(dp[j+1].size()<dp[j].size()) dp[j+1]=dp[j];
//             tmp1=tmp2;
//             tmp2=dp[j+2];
//         }
//         // repn(j,M) cout<<i+1<<','<<j<<' '<<dp[j]<<endl;
//     }

//     cout<<dp[M]<<endl;
// }



// TLE
// int main(){
//     cin>>s>>t;

//     vector<string> dp(t.size()+1,"");
//     rep(i,s.size()){
//         vector<string> tmp=dp;
//         rep(j,t.size()){
//             if(s[i]==t[j]) dp[j+1]=tmp[j]+s[i];
//             else if(tmp[j+1].size()<dp[j].size()) dp[j+1]=dp[j];
//             else dp[j+1]=tmp[j+1];
//         }
//         // repn(j,t.size()) cout<<i+1<<','<<j<<' '<<dp[j]<<endl;
//     }

//     cout<<dp[t.size()]<<endl;
// }