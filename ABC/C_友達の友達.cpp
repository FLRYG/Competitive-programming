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
ll const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

int N,M;
vector<vector<int>> G(10);

int main(){
    cin>>N>>M;
    rep(i,M){
        int a,b;
        cin>>a>>b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }

    rep(i,N){
        int ans=0;
        rep(j,N){
            if(i==j) continue;
            rep(k,G[i].size()){
                rep(l,G[j].size()){
                    if(G[i][k]==j || G[j][l]==i) goto a;
                }
            }
            rep(k,G[i].size()){
                rep(l,G[j].size()){
                    if(G[i][k]==G[j][l]){
                        ans++;
                        goto a;
                    }
                }
            }
            a:;
        }
        cout<<ans<<endl;
    }
}

/*
int N,M;
int A[11];
int B[11];

int main(){
    cin>>N>>M;
    rep(i,M) cin>>A[i]>>B[i];

    vector<int> G[11];
    repn(i,M){
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }
    repn(i,N){
        cout<<i<<':';
        rep(j,G[i].size()){
            cout<<G[i][j]<<' ';
        }
        cout<<endl;
    }

    repn(i,N){
        int ans=0;
        repn(j,N){
            if(i==j) continue;
            rep(k,G[i].size()){
                if(G[i][k]==j) goto a;
            }
            rep(k,G[i].size()){
                rep(l,G[j].size()){
                    if(G[i][k]==G[j][l]){
                        ans++;
                        goto a;
                    }
                }
            }a:;
        }
        cout<<ans<<endl;
    }
}
*/