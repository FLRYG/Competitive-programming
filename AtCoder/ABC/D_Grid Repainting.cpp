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

int a[]={1,0,-1,0};
int b[]={0,1,0,-1};

int H,W;
char s[52][52];
int G[52][52];

int main(){
    cin>>H>>W;
    repn(i,H) repn(j,W) cin>>s[i][j];
    repn(i,H) fill(G[i]+1,G[i]+1+W,-1);

    queue<P> que;
    que.push(P(1,1));
    G[1][1]=0;
    while(!que.empty()){
        P p=que.front();
        int i=p.first, j=p.second;
        que.pop();
        rep(k,4){
            if(s[i+a[k]][j+b[k]]=='.' && G[i+a[k]][j+b[k]]==-1 &&
            1<=i+a[k] && i+a[k]<=H && 1<=j+b[k] && j+b[k]<=W){
                G[i+a[k]][j+b[k]]=G[i][j]+1;
                que.push(P(i+a[k],j+b[k]));
            }
        }
    }

    if(G[H][W]==-1){
        cout<<-1<<endl;
        return 0;
    }

    int wh=0;
    repn(i,H){
        repn(j,W){
            if(s[i][j]=='.') wh++;
        }
    }
    int ans=wh-(G[H][W]+1);

    cout<<ans<<endl;
}