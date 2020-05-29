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
int h[300000];

int main(){
    cin>>N;
    rep(i,N) cin>>h[i];

    int ans=1;
    int s=0,t=0,u=0;
    bool plus=true;
    repn(i,N-1){
        if(h[i-1]<h[i]){
            if(!plus){
                s=t=u=i-1;
            }
            t++;
            u++;
            plus=true;
        }else if(h[i-1]>h[i]){
            u++;
            plus=false;
        }
        ans=max(ans,u-s+1);
    }

    cout<<ans<<endl;
}