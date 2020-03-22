#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI=3.1415926535;
double a,b,x;

int main(){
    cin>>a>>b>>x;

    double ans;
    if(x>=(a*b*a)/2){
        ans=atan(2/a*(b-x/(a*a)));
    }else{
        ans=atan((a*b*b)/(2*x));
    }

    ans*=360/(2*PI);

    cout<<setprecision(16)<<ans;
}