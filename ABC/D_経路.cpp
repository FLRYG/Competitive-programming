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
//typedef pair<int,int> P;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int I[]={1,0,-1,0};
int J[]={0,1,0,-1};

int H,W;
int a[1000][1000];
int cnt[1000][1000];

int main(){
    cin>>H>>W;
    rep(i,H) rep(j,W) cin>>a[i][j];

    rep(i,H){
        rep(j,W){
            rep(k,4){
                int x=i+I[k];
                int y=j+J[k];
                if(0<=x && x<H && 0<=y && y<W && a[x][y]>a[i][j]){
                    cnt[i][j]++;
                }
            }
        }
    }

    ll ans=0;
    rep(i,H){
        rep(j,W){
            if(cnt[i][j]==0){
                vector<vector<int>> v(H,vector<int>(W,0));
                
            }
        }
    }
}