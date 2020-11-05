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
typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int I[]={1,0,-1,0};
int J[]={0,1,0,-1};

int H,W;
string S[1000];

int main(){
    cin>>W>>H;
    rep(i,H) cin>>S[i];

    vector<vector<int>> chk(H,vector<int>(W,0));
    P pos1, pos2;
    rep(i,H){
        rep(j,W){
            if(S[i][j]=='1'){
                pos1=P(i,j);
                S[i][j]='.';
            }
            if(S[i][j]=='2'){
                pos2=P(i,j);
                S[i][j]='.';
            }
        }
    }
    
    P skip(-1,-1);
    chk[pos1.first][pos1.second]=1;
    chk[pos2.first][pos2.second]=2;
    queue<P> q1,q2;
    q1.push(pos1);
    q1.push(skip);
    q2.push(pos2);
    q2.push(skip);
    int cnt2=1;
    int ans=0;
    // cout<<ans<<endl;
    // rep(i,H){
    //     rep(j,W){
    //         cout<<chk[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    while(!q1.empty()){
        ans++;
        while(!q1.empty()){
            P p1=q1.front(); q1.pop();
            if(p1==skip) break;
            rep(k,4){
                int i=p1.first+I[k];
                int j=p1.second+J[k];
                if(0<=i && i<H && 0<=j && j<=W && S[i][j]=='.'
                && chk[i][j]!=1){
                    if(chk[i][j]==2) cnt2--;
                    chk[i][j]=1;
                    q1.push(P(i,j));
                }
            }
        }
        q1.push(skip);

        if(cnt2==0) break;

        while(!q2.empty()){
            P p2=q2.front(); q2.pop();
            if(p2==skip) break;
            if(chk[p2.first][p2.second]!=2) continue;
            rep(k,4){
                int i=p2.first+I[k];
                int j=p2.second+J[k];
                if(0<=i && i<H && 0<=j && j<=W && S[i][j]=='.'
                && chk[i][j]==0){
                    cnt2++;
                    chk[i][j]=2;
                    q2.push(P(i,j));
                }
            }
        }
        q2.push(skip);

        // cout<<ans<<endl;
        // rep(i,H){
        //     rep(j,W){
        //         cout<<chk[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
    }

    cout<<ans<<endl;
}