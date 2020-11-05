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
typedef pair<int,int> P;

int N;
vector<P> p;
int G[101][101];

void connect(P p1, P p2){
    G[p1.first][p2.first]=1;
    G[p1.first][p2.second]=1;
    G[p1.second][p2.first]=1;
    G[p1.second][p2.second]=1;
}

int main(){
    cin>>N;
    if(N&1){
        rep(i,N/2){
            p.push_back(P(i+1,N-i-1));
        }
        p.push_back(P(N,N));
    }else{
        rep(i,N/2){
            p.push_back(P(i+1,N-i));
        }
    }

    for(int i=0;i<p.size()-1;i++){
        for(int j=i+1;j<p.size();j++){
            connect(p[i],p[j]);
        }
    }

    int M=0;
    repn(i,N){
        repn(j,N){
            if(G[i][j]==1){
                M++;
            }
        }
    }
    cout<<M<<endl;
    repn(i,N){
        repn(j,N){
            if(G[i][j]==1){
                cout<<i<<' '<<j<<endl;
            }
        }
    }
}