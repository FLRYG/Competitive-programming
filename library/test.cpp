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
    float x;
    cin>>x;

    float a=x*(sqrt(x*x+1)-x);
    float b=x/(sqrt(x*x+1)+x);

    cout<<a<<'\n'<<b<<endl;
}