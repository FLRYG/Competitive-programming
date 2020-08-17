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
typedef long double ld;
//typedef pair<int,int> P;
//int const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

int R;
int x[3], y[3];

int main(){
    cin>>x[0]>>y[0]>>R;
    repn(i,2) cin>>x[i]>>y[i];

    string ansR="YES";
    int l=x[0]-R;
    int b=y[0]-R;
    int r=x[0]+R;
    int t=y[0]+R;
    if(x[1]<=l && y[1]<=b && r<=x[2] && t<=y[2]) ansR="NO";

    string ansB="YES";
    int A=max(abs(x[1]-x[0]),abs(x[2]-x[0]));
    int B=max(abs(y[1]-y[0]),abs(y[2]-y[0]));
    if(A*A+B*B<=R*R) ansB="NO";

    cout<<ansR<<'\n'<<ansB<<endl;
}