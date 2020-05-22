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
typedef pair<int,int> P;

double X,Y;
int N;
double x[10], y[10];

int main(){
    cin>>X>>Y>>N;
    rep(i,N) cin>>x[i]>>y[i];

    double ans=1001001001;
    rep(i,N){
        double x1=x[i], y1=y[i];
        double x2=x[(i+1)%N], y2=y[(i+1)%N];
        double a=y2-y1;
        double b=x1-x2;
        double c=x1*(y1-y2)-y1*(x1-x2);
        double d=abs(a*X+b*Y+c)/sqrt(a*a+b*b);
        ans=min(ans,d);
    }

    cout<<setprecision(16)<<ans<<endl;
}