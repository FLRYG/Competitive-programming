#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
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
string S[61];
ll dp[61][2];

int main(){
    cin>>N;
    repn(i,N) cin>>S[i];

    dp[0][0]=1;
    dp[0][1]=1;
    repn(i,N){
        rep(x,2) rep(y,2){
            int n=x;
            if(S[i]=="AND") n&=y;
            else n|=y;
            dp[i][n]+=dp[i-1][y];
        }
    }

    cout<<dp[N][1]<<endl;
    
    return 0;
}