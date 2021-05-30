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

double memo[100][100][100];

double dfs(int a, int b, int c){
    if(a==100 || b==100 || c==100) return 0;
    if(memo[a][b][c]!=0) return memo[a][b][c];
    memo[a][b][c]=(dfs(a+1,b,c)*a+dfs(a,b+1,c)*b+dfs(a,b,c+1)*c)/(a+b+c)+1;
    return memo[a][b][c];
}

int main(){
    int A,B,C;
    cin>>A>>B>>C;
    
    double ans=dfs(A,B,C);

    cout<<setprecision(16)<<ans<<endl;
    
    return 0;
}