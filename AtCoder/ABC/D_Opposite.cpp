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
double x[2], y[2];

int main(){
    cin>>N;
    rep(i,2) cin>>x[i]>>y[i];

    double cx,cy;
    cx=(double)(x[0]+x[1])/2;
    cy=(double)(y[0]+y[1])/2;

    x[0]-=cx;
    y[0]-=cy;

    double a=2*PI/N;
    double ansx,ansy;
    ansx=x[0]*cos(a)-y[0]*sin(a);
    ansy=x[0]*sin(a)+y[0]*cos(a);

    ansx+=cx;
    ansy+=cy;

    cout<<setprecision(16)<<ansx<<' '<<ansy<<endl;
    
    return 0;
}