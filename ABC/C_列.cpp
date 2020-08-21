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
        if(K==0) break;
        if(s[i]==0){
            ans=N;
            break;
        }
        while(val<=K && r<N){
            val*=s[r];
            r++;
        }
        val/=s[i];
        ans=max(ans,r-i-1);
    }

    cout<<ans<<endl;;
}