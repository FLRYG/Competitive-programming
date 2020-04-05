#include <iostream>
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

int powi(int x,int n){if(n==0)return 1;return x*powi(x,n-1);}

ll N;
const int table[3]={3,5,7};

bool _753(ll k){
    int digit=log10(k)+1;
    bool c3=false,c5=false,c7=false;
    rep(i,digit){
        if(k%10==3) c3=true;
        else if(k%10==5) c5=true;
        else if(k%10==7) c7=true;
        k/=10;
    }
    return c3&&c5&&c7;
}

int def(ll x,ll m){
    int res=0;
    rep(i,3){
        ll k=10*x+table[i];
        if(k<=m){
            //cout<<k<<' '<<_753(k)<<endl;
            if(_753(k)) res++;
            res+=def(k,m);
        }
    }
    return res;
}

int main(){
    cin>>N;
    
    int ans=def(0,N);

    cout<<ans<<endl;
}