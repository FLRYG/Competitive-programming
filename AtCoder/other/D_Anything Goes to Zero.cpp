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

int popcount(int n){
    int res=0;
    while(n>0){
        res+=n%2;
        n/=2;
    }
    return res;
}

int f(int n,int cnt){
    if(n==0) return 1;
    n%=cnt;
    return f(n,popcount(n))+1;
}

int main(){
    cin>>N>>X;

    int cnt=0;
    rep(i,N) cnt+=X[i]-'0';

    int plus=0, minus=0;
    rep(i,N) plus=(plus*2+(X[i]-'0'))%(cnt+1);
    if(cnt>1) rep(i,N) minus=(minus*2+(X[i]-'0'))%(cnt-1);
    //cout<<plus<<' '<<minus<<'\n'<<endl;
    
    vector<int> tmpp(N+1); tmpp[N]=0;
    vector<int> tmpm(N+1); tmpm[N]=0;
    rep(i,N) tmpp[N-i-1]=(tmpp[N-i]*2+1)%(cnt+1);
    if(cnt>1) rep(i,N) tmpm[N-i-1]=(tmpm[N-i]*2+1)%(cnt-1);
    //rep(i,N) cout<<tmpp[i]<<endl;cout<<endl;
    //rep(i,N) cout<<tmpm[i]<<endl;cout<<endl;

    rep(i,N){
        int n=0;
        int diff=0;
        if(X[i]=='0'){
            diff=(tmpp[i]-tmpp[i+1]+cnt+1)%(cnt+1);
            n=(plus+diff+cnt+1)%(cnt+1);
        }else if(cnt>1){
            diff=(tmpm[i]-tmpm[i+1]+cnt-1)%(cnt-1);
            n=(minus-diff+cnt-1)%(cnt-1);
        }else{
            cout<<0<<endl;
            continue;
        }
        //cout<<diff<<' '<<n<<endl;
        //cout<<n<<' '<<popcount(n)<<endl;
        int ans=f(n,popcount(n));
        cout<<ans<<endl;//cout<<endl;
    }
}