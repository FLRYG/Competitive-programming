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

double A,B,C;

double f(double t){
    return A*t+B*sin(C*PI*t); 
}

int main(){
    cin>>A>>B>>C;

    double r=1;
    while(f(r)<100) r++;
    double l=r-1;

    while(abs(f(r)-100)>1e-6){
        double mid=(l+r)/2;
        if(f(mid)<100) l=mid;
        else r=mid;
    }

    //cout<<setprecision(16)<<f(r)<<endl;
    cout<<setprecision(16)<<r<<endl;
}