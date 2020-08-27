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

double P;

inline double f(double x){
    return x+P/pow(2,2*x/3);
}

inline double df(double x){
    return 1+P*log(2)*(-2)/pow(2,2*x/3)/3;
}

//二分法
int main(){
    cin>>P;

    double low=0, high=100;
    while(high-low>0.0000000001){
        double mid=(low+high)/2;
        if(df(mid)<0) low=mid;
        else high=mid;
    }

    cout<<setprecision(16)<<f(high)<<endl;
}

/*
//三分探索
int main(){
    cin>>P;

    double low=0, high=100;
    while(high-low>0.0000000001){
        double left=high/3+2*low/3;
        double right=2*high/3+low/3;
        if(f(left)>f(right)) low=left;
        else high=right;
    }

    cout<<setprecision(16)<<f(high)<<endl;
}
*/