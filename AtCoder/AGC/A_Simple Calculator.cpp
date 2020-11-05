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

ll x,y;

int main(){
    cin>>x>>y;

    ll ans=1001001001001001;
    if(x<=y) ans=min(ans,y-x);
    if(-x<=y) ans=min(ans,1+y+x);
    if(x<=-y) ans=min(ans,1-y-x);
    if(-x<=-y) ans=min(ans,2-y+x);

    cout<<ans<<endl;
}