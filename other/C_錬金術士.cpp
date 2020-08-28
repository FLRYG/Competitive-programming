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

string S[3];
ll cnt[3][26];

int main(){
    rep(i,3) cin>>S[i];

    rep(i,3){
        rep(j,26){
            cnt[S[i]-'0']++;
        }
    }

    ll N1=N2=S[0].size();
    string ans="NO";
    rep(i,26){
        if(cnt[0][i]+cnt[1][i]<cnt[2][i]){
            cout<<ans<<endl;
            return 0;
        }
        if(cnt[0][i]+cnt[1][i]==cnt[]){

        }
    }
}