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

pair<int,int> p1,p2;
pair<int,int> p3,p4;

int main(){
    cin>>p1.first>>p1.second>>p2.first>>p2.second;

    p3.first=p2.first+(p1.second-p2.second);
    p3.second=p2.second+(p2.first-p1.first);
    p4.first=p3.first+(p2.second-p3.second);
    p4.second=p3.second+(p3.first-p2.first);

    cout<<p3.first<<' '<<p3.second<<' '<<p4.first<<' '<<p4.second;
}