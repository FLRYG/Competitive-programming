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
//typedef pair<ll,ll> P;
//ll const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

int N;
string s[10000];

int main(){
    cin>>N;
    rep(i,N) cin>>s[i];

    int ans=0;
    int ra=0, lb=0, ba=0;
    rep(i,N){
        if(s[i][0]=='B' && s[i][s[i].size()-1]=='A') ba++;
        else if(s[i][s[i].size()-1]=='A') ra++;
        else if(s[i][0]=='B') lb++;
        rep(j,s[i].size()-1){
            if(s[i][j]=='A' && s[i][j+1]=='B') ans++;
        }
    }

    if(ba>0){
        ans+=ba-1;
        if(ra>0){ans++;ra--;}
        if(lb>0){ans++;lb--;}
    }
    ans+=min(ra,lb);

    cout<<ans<<endl;
}