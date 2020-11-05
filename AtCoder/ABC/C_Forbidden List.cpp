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

int X,N;
int cnt[102];

int main(){
    cin>>X>>N;
    rep(i,N){
        int p;
        cin>>p;
        cnt[p]++;
    }

    int dis=X;
    int ans=0;
    rep(i,102){
        if(cnt[i]==0){
            if(abs(i-X)<dis){
                dis=abs(i-X);
                ans=i;
            }
        }
    }
    cout<<ans<<endl;
}