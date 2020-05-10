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

ll A,B,C,K;

int main(){
    cin>>A>>B>>C>>K;

    ll ans=0;

    ans+=min(A,K);
    K-=A;
    K=max(K,(ll)0);

    K-=B;
    K=max(K,(ll)0);

    ans+=-1*min(C,K);
    K-=C;
    K=max(K,(ll)0);

    cout<<ans<<endl;
}