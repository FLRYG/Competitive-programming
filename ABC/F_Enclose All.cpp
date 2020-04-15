#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

double N;
double x[50],y[50];

int main(){
    cin>>N;
    rep(i,N) cin>>x[i]>>y[i];

    double minX=100100, maxX=0;
    double minY=100100, maxY=0;
    rep(i,N){
        minX=min(minX,x[i]);
        maxX=max(maxX,x[i]);
        minY=min(minY,y[i]);
        maxY=max(maxY,y[i]);
    }

    double cx=(minX+maxX)/2;
    double cy=(minY+maxY)/2;
    double ans=0;
    rep(i,N){
        double dis=(x[i]-cx)*(x[i]-cx)+(y[i]-cy)*(y[i]-cy);
        ans=max(ans,dis);
    }

    ans=sqrt(ans);
    cout<<setprecision(10)<<ans<<endl;
}