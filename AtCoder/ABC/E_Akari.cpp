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
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int I[]={1,0,-1,0};
int J[]={0,1,0,-1};

int H,W,N,M;
char S[1500][1500];

int main(){
    cin>>H>>W>>N>>M;
    rep(i,H) rep(j,W) S[i][j]='.';
    rep(i,N){
        int a,b;
        cin>>a>>b;
        S[a-1][b-1]='o';
    }
    rep(i,M){
        int a,b;
        cin>>a>>b;
        S[a-1][b-1]='#';
    }

    int ans=0;
    rep(i,H){
        rep(j,W){
            if(S[i][j]=='o'){
                rep(k,4){
                    int x=i;
                    int y=j;
                    while(0<=x+I[k] && x+I[k]<H && 0<=y+J[k] && y+J[k]<W &&
                    S[x+I[k]][y+J[k]]!='#' &&  S[x+I[k]][y+J[k]]!='o'){
                        x+=I[k];
                        y+=J[k];
                        S[x][y]='w';
                    }
                }
            }
        }
    }
    //rep(i,H){rep(j,W){cout<<S[i][j];}cout<<endl;}

    rep(i,H) rep(j,W) if(S[i][j]=='o' || S[i][j]=='w') ans++;

    cout<<ans<<endl;
    
    return 0;
}