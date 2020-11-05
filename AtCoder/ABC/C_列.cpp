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
#define rep(i,n) for(ll i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N,K;
ll s[100000];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>s[i];

    ll r=0;
    ll val=1;
    ll ans=0;
    rep(i,N){
        if(s[i]==0){
            ans=N;
            break;
        }
        val=max(val,(ll)1);
        r=max(r,i);
        while(r<N && val*s[r]<=K){
            val*=s[r];
            r++;
        }
        ans=max(ans,r-i);
        val/=s[i];
    }

    cout<<ans<<endl;
}