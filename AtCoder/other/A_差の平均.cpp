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
int const INF=2147483647;
ll const LINF=9223372036854775807;
ll const MOD=1000000007;

ll N;
ll a[100];

int main(){
    cin>>N;
    rep(i,N) cin>>a[i];

    ll sum=0;
    rep(i,N-1) sum+=a[i+1]-a[i];

    double ans=(double)sum/(N-1);

    cout<<setprecision(16)<<ans<<endl;
    
    return 0;
}