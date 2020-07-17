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

int n;

int main(){
    cin>>n;

    int ans=INT32_MAX;
    repn(h,1000){
        repn(w,1000){
            if(h*w>n) break;
            int res=abs(h-w)+(n-h*w);
            ans=min(ans,res);
        }
    }

    cout<<ans<<endl;
}