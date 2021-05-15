#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <chrono>
#include <random>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
// typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int H,W;
char A[2001][2001];

int main(){
    cin>>H>>W;
    rep(i,H) rep(j,W) cin>>A[i][j];

    vector<vector<int>> scr(H+1,vector<int>(W+1,0));
    for(int i=H-1;i>=0;i--){
        for(int j=W-1;j>=0;j--){
            if(i==H-1 && j==W-1) continue;
            if(!((i&1)^(j&1))){    //高橋
                // scr[i][j]=max(scr[i+1][j],scr[i][j+1]);
                // if(i==0 && j==0) continue;
                // if(A[i][j]=='+') scr[i][j]-=1;
                // else scr[i][j]+=1;
                int a=-INF, b=-INF;
                if(i+1<H){
                    if(A[i+1][j]=='+') a=1;
                    else a=-1;
                    a+=scr[i+1][j];
                }
                if(j+1<W){
                    if(A[i][j+1]=='+') b=1;
                    else b=-1;
                    b+=scr[i][j+1];
                }
                scr[i][j]=max(a,b);
            }else{
                // scr[i][j]=min(scr[i+1][j],scr[i][j+1]);
                // if(A[i][j]=='+') scr[i][j]+=1;
                // else scr[i][j]-=1;
                int a=INF, b=INF;
                if(i+1<H){
                    if(A[i+1][j]=='-') a=1;
                    else a=-1;
                    a+=scr[i+1][j];
                }
                if(j+1<W){
                    if(A[i][j+1]=='-') b=1;
                    else b=-1;
                    b+=scr[i][j+1];
                }
                scr[i][j]=min(a,b);
            }
        }
    }

    // rep(i,H){
    //     rep(j,W) cout<<scr[i][j]<<' ';
    //     cout<<endl;
    // }

    string ans="Draw";
    if(scr[0][0]>0) ans="Takahashi";
    if(scr[0][0]<0) ans="Aoki";
    
    cout<<ans<<endl;

    return 0;
}