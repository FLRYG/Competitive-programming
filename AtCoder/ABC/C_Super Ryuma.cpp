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

ll r[2];
ll c[2];

int main(){
    rep(i,2) cin>>r[i]>>c[i];

    int ans;
    if(r[0]+c[0]==r[1]+c[1]
    || r[0]-c[0]==r[1]-c[1]
    || abs(r[0]-r[1])+abs(c[0]-c[1])<=3){
        ans=1;
    }else 
    
    return 0;
}