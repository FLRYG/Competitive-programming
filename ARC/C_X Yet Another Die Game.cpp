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

ll x;

int main(){
    cin>>x;

    ll ans=x/11*2;
    ll m=x%11;
    if(m!=0){
        if(m<=6) ans++;
        else ans+=2;
    }

    cout<<ans<<endl;
}