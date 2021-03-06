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

string S;

int main(){
    cin>>S;

    ll ans=0;
    rep(i,S.size()){
        if(S[i]=='U'){
            ans+=S.size()-i-1;
            ans+=2*i;
        }
        if(S[i]=='D'){
            ans+=2*(S.size()-i-1);
            ans+=i;
        }
    }

    cout<<ans<<endl;
}