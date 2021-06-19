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

int main(){
    cin>>N>>K;

    ll ans=0;
    if(N==1) ans=K;
    else if(N==2) ans=K*(K-1)%MOD;
    else if(N==3) ans=K*(K-1)%MOD*(K-2)%MOD;
    else if(N==4) ans=K*(K-1)%MOD*(K-2)%MOD*(K-3)%MOD;
    else{
        ans=K*(K-1)%MOD*(K-2)%MOD*(K-3)%MOD*(N-4)%MOD*(K-4)%MOD;
    }

    cout<<ans<<endl;
    
    return 0;
}