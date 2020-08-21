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
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

double n,m;

int main(){
    cin>>n>>m;

    double N=(n*60+m)/2;
    if(N>=360) N-=360;
    double M=6*m;

    double ans=min(abs(N-M),360-abs(N-M));

    cout<<setprecision(16)<<ans<<endl;
}