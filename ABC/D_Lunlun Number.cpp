#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#define rep(i,n) for(ll i=0;i<n;i++)
#define repn(i,n) for(ll i=1;i<=n;i++)
using namespace std;
typedef long long ll;

ll K;
queue<ll> lun;

int main(){
    repn(i,9) lun.push(i);
    cin>>K;

    ll ans;
    repn(i,K){
        ll x=lun.front();
        lun.pop();
        if(i==K){
           ans=x; 
        }else{
            if(x%10==0){
                lun.push(10*x);
                lun.push(10*x+1);
            }else if(x%10==9){
                lun.push(10*x+8);
                lun.push(10*x+9);
            }else{
                lun.push(10*x+(x%10)-1);
                lun.push(10*x+(x%10));
                lun.push(10*x+(x%10)+1);
            }
        }
    }

    cout<<ans<<endl;
}