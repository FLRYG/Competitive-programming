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
ll const MOD=1'000'000'007;

string S;
int cnt[26];

int main(){
    cin>>S;

    rep(i,S.size()) cnt[S[i]-'a']++;

    int odd=0;
    rep(i,26){
        if(cnt[i]==0) continue;
        if(cnt[i]&1) odd++;
    }

    int ans;
    if(odd==0) ans=S.size();
    else ans=(S.size()-odd)/2/odd*2+1;

    cout<<ans<<endl;
}