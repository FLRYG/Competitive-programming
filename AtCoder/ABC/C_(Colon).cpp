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

double pi=3.1415926535897932384626433;
double A,B,H,M;

int main(){
    cin>>A>>B>>H>>M;

    double h=pi/6*H+(pi/6)/60*M;
    double m=M/60*2*pi;
    double a=cos(h-m);

    double ans=A*A+B*B-2*A*B*a;
    ans=sqrt(ans);

    cout<<setprecision(20)<<ans<<endl;
}