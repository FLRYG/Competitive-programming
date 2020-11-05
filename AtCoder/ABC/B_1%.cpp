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
using namespace std;
typedef long long ll;

ll X;

int main(){
    cin>>X;

    ll m=100;
    ll ans=0;
    while(m<X){
        m*=1.01;
        ans++;
    }

    cout<<ans<<endl;
}