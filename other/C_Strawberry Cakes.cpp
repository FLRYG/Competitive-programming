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
char s[300][300];
int ans[300][300];

int main(){
    cin>>H>>W>>K;
    rep(i,H) rep(j,W) cin>>s[i][j];
   
    int u=0,d=0;
    rep(i,H){
        u=d;
        d++;
        int sum=0;
        rep(j,W){
            if(s[i][j]=='#') sum++;
        }
    }

    rep(i,H){
        rep(j,W){
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }
}