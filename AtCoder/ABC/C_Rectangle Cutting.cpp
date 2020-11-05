#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

double W,H,x,y;

int main(){
    cin>>W>>H>>x>>y;

    double ans=(W*H)/2;

    int ans2;
    if(x==W/2 && y==H/2){
        ans2=1;
    }else{
        ans2=0;
    }

    cout<<setprecision(10)<<ans<<' '<<ans2<<endl;
}