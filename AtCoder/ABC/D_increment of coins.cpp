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

int A,B,C;
double dp[100][100][100];

double f(int A, int B, int C){
    if(A==100 || B==100 || C==100) return 0;
    if(dp[A][B][C]==0)
        dp[A][B][C]=(A*f(A+1,B,C)+B*f(A,B+1,C)+C*f(A,B,C+1))/(double)(A+B+C)+1;
    return dp[A][B][C];
}

int main(){
    cin>>A>>B>>C;

    cout<<setprecision(16)<<f(A,B,C)<<endl;

    return 0;
}