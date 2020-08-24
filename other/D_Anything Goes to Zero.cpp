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
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
string X;

int f(int n,int cnt){
    if(n==0) return 1;
    n%=cnt;
    return f(n,__builtin_popcount(n))+1;
}

int main(){
    cin>>N>>X;

    int cnt=0;
    rep(i,N) cnt+=X[i]-'0';

    int plus=0, minus=0;
    rep(i,N) plus=(plus*2+(X[i]-'0'))%(cnt+1);
    rep(i,N) minus=(minus*2+(X[i]-'0'))%(cnt-1);
    cout<<plus<<' '<<minus<<endl;

    rep(i,N){
        int n;
        if(X[i]==0) n=plus;
        else n=minus;
        cout<<n<<' '<<__builtin_popcount(n)<<endl;
        int ans=f(n,__builtin_popcount(n));
        cout<<ans<<endl;
    }
}