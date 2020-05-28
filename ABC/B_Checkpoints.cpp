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

int N,M;
int a[50],b[50],c[50],d[50];

int main(){
    cin>>N>>M;
    rep(i,N) cin>>a[i]>>b[i];
    rep(i,M) cin>>c[i]>>d[i];

    rep(i,N){
        int ans;
        int dis=1001001001;
        rep(j,M){
            int dd=abs(a[i]-c[j])+abs(b[i]-d[j]);
            if(dd<dis){
                dis=dd;
                ans=j+1;
            }
        }
        cout<<ans<<endl;
    }
}