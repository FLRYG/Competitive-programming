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
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;
typedef long double ld;

ll N;
ll ans[10001];

int main(){
    cin>>N;

    repn(x,150){
        repn(y,150){
            repn(z,150){
                ll res=x*x+y*y+z*z+x*y+y*z+z*x;
                if(res<=N) ans[res]++;
            }
        }
    }

    repn(i,N) cout<<ans[i]<<endl;
}