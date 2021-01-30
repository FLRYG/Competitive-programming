#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
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

ll X,Y,A,B;

int main(){
    cin>>X>>Y>>A>>B;

    if(Y/A<=X)

    ll ans=0, cnt=0;
    while(X<Y){
        cout<<X<<endl;
        ans=max(ans,cnt+(Y-X-1)/B);
        X*=A;
        cnt++;
    }

    cout<<ans<<endl;
    
    return 0;
}