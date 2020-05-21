#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int main(){
    double x;
    cin>>x;

    double a=x*(sqrt(pow(x,2)+1)-x);
    double b=x/(sqrt(pow(x,2)+1)+x);

    cout<<setprecision(16)<<"a= "<<a<<"\nb= "<<b<<endl;
}