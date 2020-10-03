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

int main(){
    cin>>N>>S;

    vector<vector<int>> cnt(4,vector<int>(N+1,0));
    rep(i,N){
        rep(j,4) cnt[j][i+1]=cnt[j][i];
        if(S[i]=='A') cnt[0][i+1]++;
        if(S[i]=='T') cnt[1][i+1]++;
        if(S[i]=='C') cnt[2][i+1]++;
        if(S[i]=='G') cnt[3][i+1]++;
    }

    int ans=0;
    rep(i,N){
        for(int j=i+1;j<=N;j++){
            int a=cnt[0][j]-cnt[0][i];
            int t=cnt[1][j]-cnt[1][i];
            int c=cnt[2][j]-cnt[2][i];
            int g=cnt[3][j]-cnt[3][i];
            if(a==t && c==g) ans++;
        }
    }

    cout<<ans<<endl;
}