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

int X;

int main(){
    cin>>X;

    int ans;
    if(X<600) ans=8;
    else if(X<800) ans=7;
    else if(X<1000) ans=6;
    else if(X<1200) ans=5;
    else if(X<1400) ans=4;
    else if(X<1600) ans=3;
    else if(X<1800) ans=2;
    else if(X<2000) ans=1;

    cout<<ans<<endl;
}