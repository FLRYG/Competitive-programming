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
#include <bitset>
#include <chrono>
#include <random>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
// typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
int A[100000];

double f(double x){
    double res=0;
    rep(i,N){
        res+=A[i]-min(double(A[i]),2*x);
    }
    res/=N;
    res+=x;
    return res;
}

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    double l=0, r=1e9+1;
    double diff=1e9+1;
    while(r-l>1e-7){
        // cout<<setprecision(16)<<l<<' '<<r<<endl;
        double x1=l+(r-l)/3;
        double x2=r-(r-l)/3;
        if(f(x1)>f(x2)) l=x1;
        else r=x2;
    }

    cout<<setprecision(20)<<f(l)<<endl;
    
    return 0;
}