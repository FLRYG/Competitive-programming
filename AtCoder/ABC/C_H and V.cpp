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

int H,W,K;
char c[6][6];

int main(){
    cin>>H>>W>>K;
    rep(i,H) rep(j,W) cin>>c[i][j];

    int ans=0;
    rep(h,1<<H){
        rep(w,1<<W){
            int sum=0;
            rep(i,H){
                if(h>>i&1) continue;
                rep(j,W){
                    if(w>>j&1) continue;
                    if(c[i][j]=='#') sum++;
                }
            }
            if(sum==K) ans++;
        }
    }

    cout<<ans<<endl;
}