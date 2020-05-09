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

int main(){
    int n,x;
    int a[100000];
    cin>>n>>x;
    rep(i,n) cin>>a[i];

    ll ans=0;
    repn(i,n-1){
        if(a[i-1]+a[i]>x){
            ans+=(a[i-1]+a[i])-x;
            a[i]-=(a[i-1]+a[i])-x;
            if(a[i]<0){
                a[i-1]+=a[i];
                a[i]=0;
            }
        }
    }

    cout<<ans<<endl;
}