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

ll K;

int main(){
    cin>>K;

    vector<ll> v;
    for(ll i=1;i<=1000000;i++){
        if(K%i==0){
            v.push_back(i);
            v.push_back(K/i);
        }
    }

    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    // repr(e,v) cout<<e<<' '; cout<<endl;

    ll ans=0;
    rep(i,v.size()){
        for(int j=i;j<v.size() && v[j]<=K/v[i];j++){
            if(K%(v[i]*v[j])==0 && K/(v[i]*v[j])>=v[j]){
                // cout<<v[i]<<' '<<v[j]<<' '<<K/(v[i]*v[j])<<endl;
                ans++;
            }
        }
    }

    cout<<ans<<endl;
    
    return 0;
}