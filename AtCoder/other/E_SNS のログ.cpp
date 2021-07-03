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

int N,Q;

int main(){
    cin>>N>>Q;

    vector<vector<char>> ans(N,vector<char>(N,'N'));
    while(Q--){
        int t,a,b;
        cin>>t;
        if(t==1){
            cin>>a>>b;
            a--, b--;
            ans[a][b]='Y';
        }else if(t==2){
            cin>>a;
            a--;
            rep(i,N){
                if(ans[i][a]=='Y') ans[a][i]='Y';
            }
        }else{
            cin>>a;
            a--;
            vector<int> memo;
            rep(i,N) if(ans[a][i]=='Y'){
                rep(j,N) if(ans[i][j]=='Y' && j!=a){
                    memo.push_back(j);
                }
            }
            repr(e,memo) ans[a][e]='Y';
        }
        // rep(i,N){
        //     rep(j,N) cout<<ans[i][j]; cout<<endl;
        // }
        // cout<<endl;
    }

    rep(i,N){
        rep(j,N) cout<<ans[i][j]; cout<<endl;
    }
    
    return 0;
}