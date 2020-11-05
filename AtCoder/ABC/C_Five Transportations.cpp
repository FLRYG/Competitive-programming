#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

ll N;
ll tp[5];

int main(){
    cin>>N;
    rep(i,5) cin>>tp[i];

    ll mini=100100100100100100;
    rep(i,5){
        if(tp[i]<mini) mini=tp[i];
    }

    ll ans=N%mini==0?N/mini+4:N/mini+5;

    cout<<ans<<endl;
}