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

ll mpow(ll x,ll n){
    if(n==0) return 1;
    else if(n%2) return x*mpow(x,n-1);
    return mpow(x*x,n/2);
}

ll P,W;

int main(){
    cin>>P>>W;

    ll ans=0;
    ll n=0;
    rep(i,1000){
        n++;
        //ll cnt=0;
        ll com=1;
        ll sum=n*(P-100);
        repn(k,n){
            com*=n-k+1;
            com/=k;
            sum+=k*(W-1)*P+(n-k)*(P-100);
            // if(k*(W-1)*P+(n-k+1)*(P-100)>0) cnt+=com;
            cout<<' '<<k<<' '<<k*(W-1)*P+(k-1)*(P-100)<<endl;
        }
        //cout<<n<<' '<<cnt<<endl;
        if(0<sum) ans++;
        else{
            if(ans==0) cout<<-1<<endl;
            else cout<<ans<<endl;
            return 0;
        }
    }

    cout<<-2<<endl;
    
    return 0;
}