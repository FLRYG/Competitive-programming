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

double dfs(int x, int y, int z){
    if(x==0 && y==0 && z==0) return 0;
    double res=1;
    if(x>0) res+=dfs(x-1,y,z)*(x/N);
    if(y>0) res+=dfs(x+1,y-1,z)*(y/N);
    if(z>0) res+=dfs(x,y+1,z-1)*(z/N);
    return res;
}

int main(){
    cin>>N;
    rep(i,N) cin>>a[i];

    int x,y,z;
    rep(i,N){
        if(a[i]==1) x++;
        if(a[i]==2) y++;
        if(a[i]==3) z++;
    }

    cout<<dfs(x,y,z)<<endl;
    
    return 0;
}