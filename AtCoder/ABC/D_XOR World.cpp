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
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

ll A,B;

ll f(ll x){
    if((x+1)%2==0){
        if((x+1)/2%2==0) return 0;
        else return 1;
    }else{
        if((x+1)/2%2==0) return 0^x;
        else return 1^x;
    }
}

int main(){
    cin>>A>>B;

    ll ans=f(A-1)^f(B);

    cout<<ans<<endl;
}