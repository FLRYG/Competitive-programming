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
string S[3];
int cnt[3][26];

int main(){
    rep(i,3) cin>>S[i];
    N=S[0].size()/2;

    rep(i,3){
        rep(j,2*N){
            cnt[i][S[i][j]-'A']++;
        }
    }

    int suminf=0;
    int sumsup=0;
    rep(i,26){
        int mini=max(0,cnt[2][i]-cnt[1][i]);
        int maxi=min(cnt[2][i],cnt[0][i]);
        if(mini>cnt[0][i]){
            cout<<"NO"<<endl;
            return 0;
        }
        suminf+=mini;
        sumsup+=maxi;
    }

    if(suminf<=N && N<=sumsup){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}