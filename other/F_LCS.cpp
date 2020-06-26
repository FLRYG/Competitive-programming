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
int dp[3000][3000];

int main(){
    cin>>s>>t;

    repn(i,s.size()){
        repn(j,t.size()){
            if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+1;
        }
    }
}