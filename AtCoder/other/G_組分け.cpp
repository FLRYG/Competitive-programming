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

int N;
int A[10][10];

int main(){
    cin>>N;
    rep(i,N-1) for(int j=i+1;j<N;j++) cin>>A[i][j];
    rep(i,N-1) for(int j=i+1;j<N;j++) A[j][i]=A[i][j];

    int NN=1;
    rep(i,N) NN*=3;

    int ans=-INF;
    rep(i,NN){
        vector<int> x,y,z;
        int n=i;
        rep(j,N){
            int m=n%3;
            if(m==0) x.push_back(j);
            if(m==1) y.push_back(j);
            if(m==2) z.push_back(j);
            n/=3;
        }
        int res=0;
        if(x.size()) rep(j,x.size()-1) for(int k=j+1;k<x.size();k++){
            res+=A[x[j]][x[k]];
        }
        if(y.size()) rep(j,y.size()-1) for(int k=j+1;k<y.size();k++){
            res+=A[y[j]][y[k]];
        }
        if(z.size()) rep(j,z.size()-1) for(int k=j+1;k<z.size();k++){
            res+=A[z[j]][z[k]];
        }
        // cout<<res<<endl;
        ans=max(ans,res);
    }   

    cout<<ans<<endl;
    
    return 0;
}