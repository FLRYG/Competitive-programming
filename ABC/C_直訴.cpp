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
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;
typedef long double ld;

double x[3], y[3];

int main(){
    rep(i,3) cin>>x[i]>>y[i];

    repn(i,2){
        x[i]-=x[0];
        y[i]-=y[0];
    }

    double ans=abs(x[1]*y[2]-x[2]*y[1])/2.0;

    cout<<fixed<<setprecision(1)<<ans<<endl;
}