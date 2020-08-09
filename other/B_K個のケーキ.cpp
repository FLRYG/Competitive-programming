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
ll const MOD=1000000007;

int K,T;
int a[100];

int main(){
    cin>>K>>T;
    rep(i,T) cin>>a[i];

    sort(a,a+T,greater<>());

    int x=0,y=0;
    rep(i,T){
        if(x<y) x+=a[i];
        else y+=a[i];
    }

    int ans=max(0,abs(x-y)-1);

    cout<<ans<<endl;
}