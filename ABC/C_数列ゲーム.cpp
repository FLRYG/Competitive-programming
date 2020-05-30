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

const int MIN=-1001001001;

int N;
int a[50];

int main(){
    cin>>N;
    rep(i,N) cin>>a[i];

    int ans=MIN;
    rep(i,N){
        int aomax=MIN;
        int tamax=MIN;
        rep(j,N){
            if(i==j) continue;
            int aoki=0, taka=0;
            for(int k=0;k<=abs(j-i);k++){
                if(k&1) aoki+=a[k+min(i,j)];
                else taka+=a[k+min(i,j)];
            }
            if(aoki>aomax){
                aomax=aoki;
                tamax=taka;
            }
        }
        ans=max(ans,tamax);
    }

    cout<<ans<<endl;
}