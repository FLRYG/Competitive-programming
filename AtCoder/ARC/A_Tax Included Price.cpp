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

ll t,N;

int main(){
    cin>>t>>N;

    ll l=0, r=1001001001001001;
    while(r-l>1){
        ll mid=(l+r)/2;
        ll A=100*mid/(100+t);
        ll cnt=(100+t)*A/100-A+max(0LL,mid-(100+t)*A/100-1);
        // cout<<A<<' '<<(100+t)*A/100<<' '<<mid<<' '<<cnt<<endl;
        if(cnt<N) l=mid;
        else r=mid;
    }

    cout<<l<<endl;
    
    return 0;
}