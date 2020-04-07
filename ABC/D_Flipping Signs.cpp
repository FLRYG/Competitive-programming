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

ll N;
ll nega=0;
ll ans=0;
ll minimum=1'000'000'000;

int main(){
    cin>>N;
    rep(i,N){
        ll a;
        cin>>a;
        ans+=abs(a);
        nega+=a<0;
        minimum=min(minimum,abs(a));
    }

    if(nega%2==1) ans-=minimum*2;

    cout<<ans<<endl;
}