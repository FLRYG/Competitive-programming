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
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int I[]={1,0,-1,0};
int J[]={0,1,0,-1};
int H,W;
int ch,cw;
int dh,dw;
char S[1000][1000];
int cnt[1000][1000];

int main(){
    cin>>H>>W;
    cin>>ch>>cw>>dh>>dw;
    ch--, cw--, dh--, dw--;
    rep(i,H) rep(j,W) cin>>S[i][j];
    rep(i,H) rep(j,W) cnt[i][j]=INF;

    cnt[ch][cw]=0;
    queue<P> q1;
    queue<P> q2;
    q1.push(P(ch,cw));
    while(!q1.empty()){
        while(!q1.empty()){
            //cout<<"AAA"<<endl;
            P p=q1.front(); q1.pop();
            //cout<<p.first<<' '<<p.second<<endl;
            rep(k,4){
                int i=p.first+I[k];
                int j=p.second+J[k];
                if(0<=i && i<H && 0<=j && j<W && S[i][j]=='.' 
                && cnt[p.first][p.second]<cnt[i][j]){
                    //cout<<cnt[p.first][p.second]<<endl;
                    cnt[i][j]=cnt[p.first][p.second];
                    q1.push(P(i,j));
                }
            }
            q2.push(p);
        }

        while(!q2.empty()){
            P p=q2.front(); q2.pop();
            for(int i=-2;i<=2;i++){
                for(int j=-2;j<=2;j++){
                    int x=i+p.first;
                    int y=j+p.second;
                    if(0<=x && x<H && 0<=y && y<W && S[x][y]=='.'
                    && cnt[p.first][p.second]+1<cnt[x][y]){
                        cnt[x][y]=cnt[p.first][p.second]+1;
                        q1.push(P(x,y));
                    }
                }
            }
        }
    }

    int ans=cnt[dh][dw];
    if(ans==INF) ans=-1;
    cout<<ans<<endl;
}



/*
int H,W;
int ch,cw;
int dh,dw;
char S[1000][1000];
int cnt[1000][1000];
int I[]={1,0,-1,0};
int J[]={0,1,0,-1};

int main(){
    cin>>H>>W>>ch>>cw>>dh>>dw;
    rep(i,H) rep(j,W) cin>>S[i][j];
    ch--,cw--,dh--,dw--;
    rep(i,H) fill(cnt[i],cnt[i]+W,INF);

    queue<P> q;
    q.push(P(ch,cw));
    cnt[ch][cw]=0;
    ll jump=0;
    while(!q.empty()){
        while(!q.empty()){
            //cout<<"AAA"<<endl;
            P p=q.front(); q.pop();
            //cout<<p.first<<' '<<p.second<<endl;
            rep(k,4){
                int i=p.first+I[k];
                int j=p.second+J[k];
                if(0<=i && i<H && 0<=j && j<W && S[i][j]=='.' 
                && cnt[p.first][p.second]<cnt[i][j]){
                    //cout<<cnt[p.first][p.second]<<endl;
                    cnt[i][j]=cnt[p.first][p.second];
                    q.push(P(i,j));
                }
            }
        }
        //rep(i,H){rep(j,W){cout<<cnt[i][j]<<' ';}cout<<endl;}cout<<endl;

        rep(i,H){
            rep(j,W){
                if(cnt[i][j]!=INF){
                    for(int k=-2;k<=2;k++){
                        for(int l=-2;l<=2;l++){
                            if(0<=i+k && i+k<H && 0<=j+l && j+l<W
                            && S[i+k][j+l]=='.' && cnt[i][j]==jump && jump+1<cnt[i+k][j+l]){
                                cnt[i+k][j+l]=jump+1;
                                q.push(P(i+k,j+l));
                            }
                        }
                    }
                }
            }
        }
        jump++;
        //rep(i,H){rep(j,W){cout<<cnt[i][j]<<' ';}cout<<endl;}cout<<endl;
    }
    

    int ans=cnt[dh][dw];
    if(ans==INF) ans=-1;
    cout<<ans<<endl;
}
*/