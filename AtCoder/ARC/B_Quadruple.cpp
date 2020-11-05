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
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N,K;

int main(){
    cin>>N>>K;

    ll ans=0;
    for(ll i=2;i<=2*N;i++){
        ll n=i;
        ll m=i-K;
        //cout<<n<<' '<<m<<' ';
        if(m<2 || 2*N<m) continue;
        n=min(n-1,2*N-n+1);
        m=min(m-1,2*N-m+1);
        // int n,m;
        // n=i-1;
        // if(i>N+1) n=1+i-max(i-N,0)*2;
        // m=j-1;
        // if(j>N+1) m=1+j-max(j-N,0)*2;
        //cout<<n<<' '<<m<<endl;
        ans+=n*m;
    }

    cout<<ans<<endl;
}