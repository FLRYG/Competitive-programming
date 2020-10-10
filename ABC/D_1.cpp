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

string N;
int n;

int main(){
    cin>>N;
    rep(i,N.size()) n*=10,n+=N[i]-'0';

    vector<vector<ll>> dp(N.size(),vector<ll>(2));
    ll ten=1;
    rep(i,N.size()-1) ten*=10;
    rep(i,N.size()){
        dp[i][0]=ten;
        if(N[i]=='1') dp[i][1]=n%ten+1;
    }

    
    rep(i,N.size()){
    }
}