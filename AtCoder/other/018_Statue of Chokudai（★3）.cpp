#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <chrono>
#include <random>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
// typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int T,L,X,Y,Q;

int main(){
    cin>>T>>L>>X>>Y>>Q;

    while(Q--){
        int E;
        cin>>E;
        double a=sqrt(pow(X,2)+pow(Y+L*sin(2*PI/T*E)/2,2));
        double b=L/2*(1-cos(2*PI/T*E));
        // cout<<a<<' '<<b<<endl;
        double ans;
        if(a==0) ans=0;
        else ans=atan(b/a)*180/PI;
        cout<<setprecision(16)<<ans<<endl;
    }
    
    return 0;
}