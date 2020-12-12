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

ll N;
ll cnt[31];

int main(){
    cin>>N;

    for(ll i=2;i<=N;i++){
        ll n=i;
        for(ll j=2;j<=i;j++){
            ll c=0;
            while(n%j==0){
                n/=j;
                c++;
            }
            cnt[j]=max(cnt[j],c);
        }
    }

    ll ans=1;
    repn(i,N){
        if(cnt[i]!=0) rep(j,cnt[i]) ans*=i;
    }
    ans++;

    cout<<ans<<endl;
    
    return 0;
}