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

ld P;

int main(){
    cin>>P;

    ld init=4;
    ld prev=init;
    rep(i,10){
        ld f=prev+P*pow(2,-3*prev/2);
        ld a=1+P*pow(2,-3*prev/2)*log(2)*(-3)/2;
        prev=prev-f/a;
    }

    ld ans=prev+P*pow(2,-3*prev/2);
    cout<<setprecision(16)<<ans<<endl;
    
}