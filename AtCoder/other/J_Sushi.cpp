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

int N;
int a[300];
vector<vector<vector<double>>> memo;

double dfs(int x, int y, int z){
    if(x==0 && y==0 && z==0) return 0;
    if(memo[x][y][z]!=-1) return memo[x][y][z];
    // f(x,y,z)=
    //     +1
    //     +f(x,y,z)*(N-x-y-z)/N
    //     +f(x-1,y,z)*x/N
    //     +f(x+1,y-1,z)*y/N
    //     +f(x,y+1,z-1)*z/N
    double m=1-(double)(N-x-y-z)/N;
    double res=1/m;
    if(x>0) res+=dfs(x-1,y,z)*x/N/m;
    if(y>0) res+=dfs(x+1,y-1,z)*y/N/m;
    if(z>0) res+=dfs(x,y+1,z-1)*z/N/m;
    // cout<<x<<' '<<y<<' '<<z<<' '<<res<<endl;
    memo[x][y][z]=res;
    return res;
}

int main(){
    cin>>N;
    rep(i,N) cin>>a[i];

    int x=0, y=0, z=0;
    rep(i,N){
        if(a[i]==1) x++;
        if(a[i]==2) y++;
        if(a[i]==3) z++;
    }

    memo=vector<vector<vector<double>>>(x+y+z+1,vector<vector<double>>(y+z+1,vector<double>(z+1,-1)));

    cout<<setprecision(16)<<dfs(x,y,z)<<endl;
    
    return 0;
}