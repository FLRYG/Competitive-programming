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
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
string S;
string T[100];

int main(){
    cin>>N>>S;
    rep(i,N) cin>>T[i];

    vector<int> dp(S.size()+1,0);
    dp[0]=1;
    repn(i,S.size()){
        rep(j,N){
            if(i<T[j].size()) continue;
            if(S.substr(i-T[j].size(),T[j].size())==T[j]){
                dp[i]+=dp[i-T[j].size()];
                dp[i]%=MOD;
            }
        }
    }
    //rep(i,S.size()+1) cout<<dp[i];cout<<endl;

    cout<<dp[S.size()]<<endl;
}