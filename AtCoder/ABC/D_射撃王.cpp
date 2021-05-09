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

ll N;
ll H[100000];
ll S[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>H[i]>>S[i];

    ll l=0, r=LINF;
    while(r-l>1){
        ll m=(l+r)/2;
        bool flag=false;
        vector<ll> cnt(N,0);
        rep(i,N){
            ll maxi=min(N-1,(m-H[i])/S[i]);
            if(maxi<0) flag=true;
            else cnt[maxi]++;
        }
        rep(i,N-1) cnt[i+1]+=cnt[i];
        rep(i,N) flag|=cnt[i]>i+1;
        if(flag) l=m;
        else r=m;
    }

    cout<<r<<endl;
    
    return 0;
}