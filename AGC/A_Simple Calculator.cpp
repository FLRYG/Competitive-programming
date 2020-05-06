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

    ll ans;
    if(x<=y){
        if(abs(x)>abs(y)) ans=y-x;
        else ans=abs(y)-abs(x)+1;
    }else{
        ans=abs(abs(x)-abs(y));
        if(x*y>0) ans+=2;
        else ans++;
    }

    cout<<ans<<endl;
}