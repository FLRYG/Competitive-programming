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

int W,H,N;
int x[100];
int y[100];
int a[100];
int G[100][100];

int main(){
    cin>>W>>H>>N;
    rep(i,N) cin>>x[i]>>y[i]>>a[i];

    rep(i,W) fill(G[i],G[i]+H,1);
    rep(n,N){
        rep(i,W){
            rep(j,H){
                switch (a[n]){
                    case 1:
                        if(i<x[n]) G[i][j]=0;
                        break;
                    case 2:
                        if(i>=x[n]) G[i][j]=0;
                        break;
                    case 3:
                        if(j<y[n]) G[i][j]=0;
                        break;
                    case 4:
                        if(j>=y[n]) G[i][j]=0;
                        break;
                    default:
                        break;
                }
            }
        }
        //rep(i,W){rep(j,H){cout<<G[i][j];}cout<<endl;}cout<<endl;
    }

    int ans=0;
    rep(i,W) rep(j,H) ans+=G[i][j];
    
    cout<<ans<<endl;
}