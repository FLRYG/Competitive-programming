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

ll X,K,D;

int main(){
    cin>>X>>K>>D;

    ll ans;
    ll cnt=abs(X)/D;
    if(K<cnt) ans=abs(abs(X)-abs(K*D));
    else{
        ans=abs(abs(X)-abs(cnt*D));
        K-=cnt;
        if(K&1) ans=abs(ans-D);
    }

    cout<<ans<<endl;
}