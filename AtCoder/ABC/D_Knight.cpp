#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

const ll P=1'000'000'007;
ll X,Y;

ll mpow(ll x,ll n){
    if (n==0) return 1;
    if(n%2==1) return x*mpow(x,n-1)%P;
    else return mpow(x*x%P,n/2)%P;
}

int main(){
    cin>>X>>Y;

    ll k,l;
    if((2*Y-X)%3==0 && (2*X-Y)%3==0){
        k=(2*Y-X)/3;
        l=(2*X-Y)/3;
        if(k<0 || l<0){
            cout<<0<<endl;
            return 0;
        }
    }else{
        cout<<0<<endl;
        return 0;
    }

    ll r=min(k,l);
    ll a=1;
    ll b=1;
    for(int i=1;i<=r;i++){
        a=a*(k+l-i+1)%P;
        b=b*i%P;
    }

    ll ans=a*mpow(b,P-2)%P;

    cout<<ans<<endl;
}