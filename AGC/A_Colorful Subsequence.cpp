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
#define MOD 1'000'000'007;

ll N;
string S;
ll memo[26];

int main(){
    cin>>N>>S;

    ll ans=1;
    rep(i,N){
        memo[S[i]-'a']++;
    }
    rep(i,26){
        ans*=memo[i]+1;
        ans%=MOD;
    }
    ans--;

    cout<<ans<<endl;
}