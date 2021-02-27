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
typedef pair<int,int> P;
// typedef pair<int,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int I[]={1,0,-1,0};
int J[]={0,1,0,-1};

int N;
char c[100][100];

int main(){
    cin>>N;
    rep(i,N) rep(j,N) cin>>c[i][j];

    queue<P> q;
    rep(i,N) rep(j,N){
        if(c[i][j]!='?') q.push({i,j});
    }
    if(q.empty()){
        q.push({0,0});
        c[0][0]='B';
    }
    while(!q.empty()){
        P p=q.front(); q.pop();
        int b=0, w=0, qq=0;
        rep(k,4){
            int i=p.first+I[k];
            int j=p.second+J[k];
            if(0<=i && i<N && 0<=j && j<N){
                if(c[i][j]=='B') b++;
                if(c[i][j]=='W') w++;
                if(c[i][j]=='?') qq++;
            }
            if(qq>0 && b);
        }
    }
    
    return 0;
}