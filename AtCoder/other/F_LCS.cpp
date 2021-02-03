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

int main(){
    cin>>s>>t;

    vector<string> dp(t.size()+1,"");
    rep(i,s.size()){
        vector<string> tmp=dp;
        rep(j,t.size()){
            if(s[i]==t[j]) dp[j+1]=tmp[j]+s[i];
            else if(tmp[j+1].size()<dp[j].size()) dp[j+1]=dp[j];
            else dp[j+1]=tmp[j+1];
        }
        // repn(j,t.size()) cout<<i+1<<','<<j<<' '<<dp[j]<<endl;
    }

    cout<<dp[t.size()]<<endl;
}