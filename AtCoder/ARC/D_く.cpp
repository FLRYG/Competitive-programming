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

int T;
int ax,ay;
int bx,by;
int cx,cy;

int main(){
    cin>>T;
    
    rep(t,T){
        cin>>ax>>ay;
        cin>>bx>>by;
        cin>>cx>>cy;

        int x,y;
        if((ax==bx || ax==cx) && (ay==by || ay==cy)) x=ax, y=ay;
        if((bx==cx || bx==ax) && (by==cy || by==ay)) x=bx, y=by;
        if((cx==ax || bx==bx) && (cy==ay || by==by)) x=cx, y=cy;

        int ans=
    }

    return 0;
}