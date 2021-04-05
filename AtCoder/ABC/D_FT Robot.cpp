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

string s;
int x,y;

int main(){
    cin>>s>>x>>y;

    vector<vector<int>> vec(2,vector<int>(0));
    int cnt=0, id=0;
    rep(i,s.size()){
        if(s[i]=='F') cnt++;
        else{
            if(cnt){
                vec[id].push_back(cnt);
                cnt=0;
            }
            id^=1;
        }
    }
    if(cnt){
        vec[id].push_back(cnt);
    }
    // rep(i,2){
    //     repr(e,vec[i]) cout<<e<<' ';
    //     cout<<endl;
    // }

    vector<int> val(2,0);
    rep(i,2) repr(e,vec[i]) val[i]+=e;
    rep(i,2) repr(e,vec[i]) e*=2;

    val[0]-=x;
    val[1]-=y;
    if(val[0]<0 || val[1]<0){
        cout<<"No"<<endl;
        return 0;
    }

    string ans="Yes";
    rep(k,2){
        vector<vector<int>> dp(vec[k].size()+1,vector<int>(val[k]+1,0));
        dp[0][0]=1;
        if(vec[k].size()>0) dp[1][0]=1;
        repn(i,vec[k].size()){
            if(k==0 && i==1) continue;
            rep(j,val[k]+1){
                dp[i][j]|=dp[i-1][j];
                if(vec[k][i-1]<=j) dp[i][j]|=dp[i-1][j-vec[k][i-1]];
            }
        }
        if(dp[vec[k].size()][val[k]]==0){
            ans="No";
            break;
        }
    }

    cout<<ans<<endl;
    
    return 0;
}