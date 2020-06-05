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

int N;
int D[51];

int main(){
    cin>>N;
    rep(i,N) cin>>D[i];
    D[N]=0;

    int ans=0;
    rep(i,N+1){
        rep(j,N+1){
            if(i==j) continue;
            int s=min(abs(D[i]-D[j]),abs(24-D[i]-D[j]));
            cout<<i<<' '<<j<<": "<<s<<endl;
            ans=max(ans,s);
        }
    }

    cout<<ans<<endl;
}