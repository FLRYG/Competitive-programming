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

double x,y,r;
ll X,Y,R;

int main(){
    cout<<floor(-1.5)<<endl;
    cin>>x>>y>>r;
    X=x*10000;
    Y=y*10000;
    R=r*10000;
    cout<<X<<endl;
    cout<<Y<<endl;
    cout<<R<<endl;

    ll l=(abs(X-R)+9999)/10000*10000;
    ll r=(X+R)/10000*10000;

    cout<<l<<' '<<r<<endl;

    ll ans=0;
    for(ll i=l;i<=r;i+=10000){
        ll y=R*R-(X-i)*(X-i);
        ll a=0,b=LINF;
        ll u=(Y+a)/10000;
        ll d=(Y-a+9999)/10000;
        ans+=u-d+1;
    }

    cout<<ans<<endl;
    
    return 0;
}

// double X,Y,R;

// int main(){
//     cin>>X>>Y>>R;

//     ll l=ceil(X-R);
//     ll r=floor(X+R);

//     ll ans=0;
//     for(ll i=l;i<=r;i++){
//         double a=sqrt(R*R-pow(X-(double)i,2));
//         ll u=floor(Y+a);
//         ll d=ceil(Y-a);
//         ans+=u-d+1;
//     }

//     cout<<ans<<endl;
    
//     return 0;
// }