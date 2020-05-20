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

ll n,m,d;

int main(){
    cin>>n>>m>>d;

    double x=(m-1)*(n-d);
    if(d!=0) x*=2;
    double y=n*n;

    double ans=x/y;
    cout<<setprecision(16)<<ans<<endl;
}