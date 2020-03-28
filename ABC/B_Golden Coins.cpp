#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

ll X;

int main(){
    cin>>X;
    
    ll ans=0;

    ans+=X/500*1000;
    X%=500;
    ans+=X/5*5;

    cout<<ans<<endl;
}