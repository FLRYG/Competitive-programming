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
//int const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

int H,W;
char A[1000][1000];
int I[]={0,-1,0,1};
int J[]={1,0,-1,0};

int main(){
    cin>>H>>W;
    rep(i,H) rep(j,W) cin>>A[i][j];

    queue<P> q;
    rep(i,H) rep(j,W){
        if(A[i][j]=='#') q.push(P(i,j));
    }
    q.push(P(-1,-1));

    int ans=0;
    while(!q.empty()){
        P p=q.front(); q.pop();
        if(p.first==-1 && p.second==-1){
            if(q.empty()) break;
            ans++;
            q.push(P(-1,-1));
        }else{
            rep(k,4){
                int i=p.first+I[k];
                int j=p.second+J[k];
                if(0<=i && i<=H && 0<=j && j<=W && A[i][j]=='.'){
                    A[i][j]='#';
                    q.push(P(i,j));
                }
            }
        }
    }

    cout<<ans<<endl;
}