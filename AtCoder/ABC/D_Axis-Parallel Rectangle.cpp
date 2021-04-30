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

ll N,K;
ll x[50];
ll y[50];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>x[i]>>y[i];

    ll ans=5*LINF;
    rep(i,N-1){
        for(int j=i+1;j<N;j++){
            ll a,b,c,d;
            a=min(x[i],x[j]);
            b=min(y[i],y[j]);
            c=max(x[i],x[j]);
            d=max(y[i],y[j]);
            ll cnt=0;
            rep(k,N){
                if(a<=x[k] && x[k]<=c && b<=y[k] && y[k]<=d){
                    cnt++;
                }
            }
            if(cnt>=K) ans=min(ans,(c-a)*(d-b));
        }
    }

    cout<<ans<<endl;
    
    return 0;
}