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
//int const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

string S;

int main(){
    cin>>S;

    int ans=0;

    rep(i,3){
        if(S[i]=='R') ans=1;
    }
    rep(i,2){
        if(S[i]=='R' && S[i+1]=='R') ans=2;
    }
    if(S=="RRR") ans=3;

    cout<<ans<<endl;
}