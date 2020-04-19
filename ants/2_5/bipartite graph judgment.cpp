#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int N,K;
vector<int> G[1000];
int color[1000];

bool dfs(int v,int c){
    color[v]=c;
    rep(i,G[v].size()){
        if(color[G[v][i]]==c){
            return false;
        }else if(color[G[v][i]]==0 && !dfs(G[v][i],-c)){
            return false;
        }
    }
    return true;
}

int main(){
    cin>>N>>K;
    rep(i,K){
        int m,n;
        cin>>m>>n;
        G[m-1].push_back(n-1);
        G[n-1].push_back(m-1);
    }

    rep(i,N){
        if(color[i]==0){
            if(dfs(i,1)==false){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }

    cout<<"Yes"<<endl;
}