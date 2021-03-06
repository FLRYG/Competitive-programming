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
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int a,b,c,d;

int main(){
    cin>>a>>b>>c>>d;

    int ans;
    if(a==c && b==d) ans=0;
    else if(a+b==c+d) ans=1;
    else if(a-b==c-d) ans=1;
    else if(abs(a-c)+abs(b-d)<=3) ans=1;
    else if((a+b+c+d)%2==0) ans=2;
    else if(abs(a-c)+abs(b-d)<=6) ans=2;
    else if(abs((a+b)-(c+d))<=3) ans=2;
    else if(abs((a-b)-(c-d))<=3) ans=2;
    else ans=3;

    cout<<ans<<endl;
    
    return 0;
}