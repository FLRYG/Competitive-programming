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

ll L;
ll B[100000];

int main(){
    cin>>L;
    rep(i,L) cin>>B[i];

    ll sum=0;
    rep(i,L) sum^=B[i];
    if(sum!=0){
        cout<<-1<<endl;
        return 0;
    }

    ll ans=0;
    rep(i,L){
        cout<<ans<<endl;
        ans^=B[i];
    }
}