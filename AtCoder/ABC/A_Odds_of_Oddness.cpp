#include <iostream>
#include <algorithm>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

double N;

int main(){
    cin>>N;

    double x=ceil(N/2);
    double ans=x/N;

    cout<<ans;
    
}