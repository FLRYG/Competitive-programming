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
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N,M;

int main(){
    cin>>N>>M;
    vector<vector<int>> G(N,vector<int>(0));
    rep(i,M){
        int a,b;
        cin>>a>>b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }

    vector<int> c(N,-1);
    queue<int> q;
    q.push(0);
    c[0]=0;
    while(!q.empty()){
        int p=q.front(); q.pop();
        repr(e,G[0]){
            if(c[e]==-1){
                c[e]=!p;
                q.push(e);
            }else if(c[p]==c[e]){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }

    cout<<"Yes"<<endl;
    return 0;
}