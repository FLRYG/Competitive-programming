#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=2147483647;
ll const LINF=9223372036854775807;
ll const MOD=1000000007;

string X;
ll M;

int main(){
    cin>>X>>M;
    int N=X.size();

    if(N==1){
        if(X[0]-'0'<=M) cout<<1<<endl;
        else cout<<0<<endl;
        return 0;
    }

    ll d=0;
    rep(i,N) d=max(d,(ll)(X[i]-'0'));

    ll l=d, r=1e18; r++;
    while(r-l>1){
        ll y=0;
        ll mid=(l+r)/2;
        rep(i,N){
            if(y>M/mid){
                r=mid;
                // cout<<mid<<' '<<y<<endl;
                goto a;
            }
            y*=mid;
            y+=X[i]-'0';
            if(y>M){
                r=mid;
                // cout<<mid<<' '<<y<<endl;
                goto a;
            }
        }
        // cout<<mid<<' '<<y<<endl;
        l=mid;
        a:;
    }
    ll ans=l-d;

    cout<<ans<<endl;

    return 0;
}