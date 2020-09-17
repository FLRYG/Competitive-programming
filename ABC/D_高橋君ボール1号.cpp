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

    double invC=1/C;

    double l=floor(A*2*C)/2/C;
    double r=l+(1/2/C);
    if(f(l)>f(r)) swap(l,r);
    while(f(r)-f(l)>1e-6){
        double m=(l+r)/2;
        if(f(m)<100) 
    }
}