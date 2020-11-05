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
    int Y=X%100;

    int res=0;
    while(Y>=5) res+=105, Y-=5;
    while(Y>=4) res+=104, Y-=4;
    while(Y>=3) res+=103, Y-=3;
    while(Y>=2) res+=102, Y-=2;
    while(Y>=1) res+=101, Y-=1;

    if(X<res) cout<<0<<endl;
    else cout<<1<<endl;
}