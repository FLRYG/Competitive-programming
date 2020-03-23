#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

double L;

int main(){
    cin>>L;
    
    double e=L/3;
    double ans=e*e*e;

    cout<<setprecision(10)<<ans<<endl;
}