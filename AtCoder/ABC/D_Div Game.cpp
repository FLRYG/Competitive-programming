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

ll N;

int main(){
    cin>>N;

    ll ans=0;
    ll n=N;
    for(int i=2;i<=sqrt(N);i++){
        ll cnt=0;
        if(n%i==0){
            while(n%i==0){
                n/=i;
                cnt++;
            }
            //cout<<i<<' '<<cnt<<endl;
            //cout<<ceil((-1+sqrt(1+8*cnt))/2.0)<<endl;
        }
        ans+=floor((-1+sqrt(1+8*cnt))/2.0);
    }
    if(n!=1) ans++;

    cout<<ans<<endl;
}