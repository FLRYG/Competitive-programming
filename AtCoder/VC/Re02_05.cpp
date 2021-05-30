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
#include <bitset>
#include <chrono>
#include <random>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
// typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N,A,B;

int main(){
    cin>>N>>A>>B;
    vector<ll> H(N);
    rep(i,N) cin>>H[i];

    ll l=0, r=INF;
    while(r-l>1){
        ll m=(r+l)/2;
        vector<ll> h=H;
        rep(i,N) h[i]-=B*m;
        ll cnt=0;
        rep(i,N){
            if(h[i]>0){
                cnt+=(h[i]+A-B-1)/(A-B);
            }
        }
        if(cnt<=m) r=m;
        else l=m;
    }

    cout<<r<<endl;
    
    return 0;
}