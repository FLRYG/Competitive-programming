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

ll N,P;
map<ll,ll> cnt;

ll pow(ll a,ll b){if(b==0)return 1;if(b&1)return a*pow(a,b-1);return pow(a*a,b/2);}

int main(){
    cin>>N>>P;

    for(int i=2;i<=1000000;i++){
        while(P%i==0){
            P/=i;
            cnt[i]++;
        }
    }
    cnt[P]++;

    ll ans=1;
    repr(e,cnt){
        ans*=max(pow(e.first,(e.second/N)),1LL);
    }

    cout<<ans<<endl;
}