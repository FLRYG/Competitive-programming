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

int x[4]={1,0,-1,0};
int y[4]={0,1,0,-1};

int N=10;
char A[10][10];
int G[10][10];

void dfs(int p, int q){
    for(int i=0;i<4;i++){
        if(0<=p+x[i] && p+x[i]<10 && 0<=q+y[i] && q+y[i]<10 &&
            A[p+x[i]][q+y[i]]=='o' && G[p+x[i]][q+y[i]]!=1){
                G[p+x[i]][q+y[i]]=1;
                dfs(p+x[i],q+y[i]);
        }
    }
}

int main(){
    int sum=0;
    rep(i,N) rep(j,N){
        cin>>A[i][j];
        if(A[i][j]=='o') sum++;
    }
    //cout<<"sum="<<sum<<"\n\n";

    string ans="NO";
    rep(i,N) rep(j,N){
        dfs(i,j);
        int x=0;
        rep(k,N) rep(l,N) x+=G[k][l];
        //cout<<i<<' '<<j<<": "<<x<<endl;
        if(sum==x) ans="YES";
        rep(k,N) fill(G[k],G[k]+N,0);
    }

    cout<<ans<<endl;
}