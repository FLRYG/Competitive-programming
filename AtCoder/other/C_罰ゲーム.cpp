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

ll L[3],R[3];

int main(){
    rep(i,3) cin>>L[i]>>R[i];

    ll P=0;
    for(ll i=L[0];i<=R[0];i++){
        ll P1=0,P2=0;
        if(i<R[1]) P1=R[1]-max(L[1],i+1)+1;
        if(i<R[2]) P2=R[2]-max(L[2],i+1)+1;
        P+=P1*P2;
    }

    double ans=(double)P/(R[0]-L[0]+1)/(R[1]-L[1]+1)/(R[2]-L[2]+1);
    cout<<setprecision(16)<<ans<<endl;
    
    return 0;
}