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

int H,W;
int A[100][100];
int B[100][100];

int main(){
    cin>>H>>W;
    rep(i,H) rep(j,W) cin>>A[i][j];
    rep(i,H) rep(j,W) cin>>B[i][j];

    int ans=0;
    rep(i,H-1) rep(j,W-1){
        int d=B[i][j]-A[i][j];
        ans+=abs(d);
        A[i][j]+=d;
        A[i][j+1]+=d;
        A[i+1][j]+=d;
        A[i+1][j+1]+=d;
    }

    rep(i,H) rep(j,W){
        if(A[i][j]!=B[i][j]){
            cout<<"No"<<endl;
            return 0;
        }
    }

    printf("Yes\n%d\n",ans);
    
    return 0;
}