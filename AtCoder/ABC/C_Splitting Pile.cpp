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

ll N;
ll a[200000];

int main(){
    cin>>N;
    rep(i,N) cin>>a[i];

    ll sum=0;
    rep(i,N) sum+=a[i];

    ll ans=LINF;
    ll x=0, y=sum;
    rep(i,N-1){
        x+=a[i];
        y-=a[i];
        ans=min(ans,abs(x-y));
    }

    cout<<ans<<endl;
}