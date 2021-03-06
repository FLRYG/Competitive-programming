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
int A[200002];

int main(){
    cin>>N>>M;
    repn(i,M) cin>>A[i];

    sort(A,A+M+1);
    A[M+1]=N+1;

    int mini=INF;
    vector<int> d;
    rep(i,M+1){
        int x=A[i+1]-A[i]-1;
        if(x==0) continue;
        mini=min(mini,x);
        d.push_back(x);
    }
    
    int ans=0;
    repr(e,d){
        ans+=(e+mini-1)/mini;
    }

    cout<<ans<<endl;
    
    return 0;
}