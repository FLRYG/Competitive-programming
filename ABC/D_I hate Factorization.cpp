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

ll pow(ll x,ll n){
    if(n==0) return 1;
    else if(n%2) return x*pow(x,n-1);
    return pow(x*x,n/2);
}

ll X;

int main(){
    cin>>X;

    if(X==1){
        cout<<0<<' '<<-1<<endl;
        return 0;
    }

    ll p=2,q;
    while(true){
        if(X%p==0){
            q=X/p;
            break;
        }
        p++;
    }

    ll A,B;
    for(ll a=-5000;a<=5000+p;a++){
        ll b=a-p;
        ll tmp=pow(a,4)*pow(b,0)
                +pow(a,3)*pow(b,1)
                +pow(a,2)*pow(b,2)
                +pow(a,1)*pow(b,3)
                +pow(a,0)*pow(b,4);
        if(tmp==q){
            A=a;
            B=b;
            break;
        }
    }

    cout<<A<<' '<<B<<endl;
}