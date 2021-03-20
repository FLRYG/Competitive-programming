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

int d(int x){
    int res=0;
    while(x>0){
        x/=10;
        res++;
    }
    return res;
}

ll N;

int main(){
    cin>>N;

    ll ans=0;
    repn(i,999999){
        ll x=i;
        rep(j,d(i)) x*=10;
        x+=i;
        // cout<<x<<endl;
        if(x<=N){
            ans++;
            // cout<<x<<endl;
        }
    }

    cout<<ans<<endl;
    
    return 0;
}