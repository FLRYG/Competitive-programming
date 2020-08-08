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
int num=0;

int ball(int l, int t, int r, int b){
    int cnt=0;
    for(int i=t;i<=b;i++){
        for(int j=l;j<=r;j++){
            if(s[i][j]=='#') cnt++;
        }
    }
    return cnt;
}

void dfs(int l, int t, int r, int b){
    //cout<<"("<<l<<","<<t<<")~("<<r<<","<<b<<")"<<endl;
    int sum=ball(l,t,r,b);
    //cout<<"  "<<sum<<endl;
    if(sum==1){
        num++;
        for(int i=t;i<=b;i++){
            for(int j=l;j<=r;j++){
                ans[i][j]=num;
            }
        }
        return;
    }

    int cnt=0;
    for(int i=t;i<=b;i++){
        for(int j=l;j<=r;j++){
            if(s[i][j]=='#') cnt++;
        }
        if(0<cnt && cnt<sum){
            dfs(l,t,r,i);
            dfs(l,i+1,r,b);
            return;
        }
    }
    
    cnt=0;
    for(int j=l;j<=r;j++){
        for(int i=t;i<=b;i++){
            if(s[i][j]=='#') cnt++;
        }
        if(0<cnt && cnt<sum){
            dfs(l,t,j,b);
            dfs(j+1,t,r,b);
            return;
        }
    }
}

int main(){
    cin>>H>>W>>K;
    rep(i,H) rep(j,W) cin>>s[i][j];
   
    dfs(0,0,W-1,H-1);

    rep(i,H){
        rep(j,W){
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }
}