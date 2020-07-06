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

ll A;

int main(){
    cin>>A;

    ll ans=-1;
    for(int i=10;i<=100000;i++){
        ll sum=0;
        ll N=i;
        ll p=1;
        while(N!=0){
            sum+=(N%10)*p;
            N/=10;
            p*=i;
        }
        if(sum==A){
            ans=i;
            break;
        }
    }

    cout<<ans<<endl;
}