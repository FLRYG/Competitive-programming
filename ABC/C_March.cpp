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
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;
typedef long double ld;

ll N;
string S[100000];
ll cnt[5];

int main(){
    cin>>N;
    rep(i,N) cin>>S[i];

    rep(i,N){
        if(S[i][0]=='M') cnt[0]++;
        if(S[i][0]=='A') cnt[1]++;
        if(S[i][0]=='R') cnt[2]++;
        if(S[i][0]=='C') cnt[3]++;
        if(S[i][0]=='H') cnt[4]++;
    }

    ll ans=0;
    rep(i,5-2){
        for(int j=i+1;j<5-1;j++){
            for(int k=j+1;k<5;k++){
                ans+=cnt[i]*cnt[j]%MOD*cnt[k]%MOD;
                ans%=MOD;
            }
        }
    }

    cout<<ans<<endl;
}