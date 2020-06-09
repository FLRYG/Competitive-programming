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

const double pi=3.14159'26535'89793;
double l1,l2,l3;

int main(){
    cin>>l1>>l2>>l3;

    double ans=pi*(l1+l2+l3)*(l1+l2+l3);
    if(l1>l2+l3){
        ans-=pi*(l1-l2-l3)*(l1-l2-l3);
    }

    cout<<setprecision(16)<<ans<<endl;
}