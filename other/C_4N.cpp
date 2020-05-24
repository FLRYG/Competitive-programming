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
typedef pair<int,int> P;

ll N;

int main(){
    cin>>N;

    ll ans[3];
    repn(h,3500){
        repn(n,3500){
            ll A=N*h*n;
            ll B=4*h*n-N*(n+h);
            if(B==0) continue;
            if(A%B==0){
                if(A/B<0) continue;
                ans[0]=h;
                ans[1]=n;
                ans[2]=A/B;
                goto a;
            }
        }
    }
    a:;

    rep(i,3) cout<<ans[i]<<' '; cout<<endl;
}