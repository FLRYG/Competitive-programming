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

int ax,ay,bx,by;
int N;
int X[101], Y[101];

int g(int a, int b, int c, int d, int e, int f){
    return a*d+b*e+c*f-a*f-b*c-d*e;
}

int main(){
    cin>>ax>>ay>>bx>>by;
    cin>>N;
    rep(i,N) cin>>X[i]>>Y[i];
    X[N]=X[0], Y[N]=Y[0];

    int ans=0;
    rep(i,N){
        int s=g(ax,ay,bx,by,X[i],Y[i]);
        int t=g(ax,ay,bx,by,X[i+1],Y[i+1]);
        int u=g(X[i],Y[i],X[i+1],Y[i+1],ax,ay);
        int v=g(X[i],Y[i],X[i+1],Y[i+1],bx,by);
        if(s*t<0 && u*v<0) ans++;
    }

    ans=ans/2+1;
    cout<<ans<<endl;
}