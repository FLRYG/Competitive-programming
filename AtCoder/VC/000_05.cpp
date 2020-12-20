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

int popcount(string S){
    int res=0;
    rep(i,S.size()) if(S[i]=='1') res++;
    return res;
}

int f(string n){
    int p=popcount(n);
    if(p==0) return 0;
    // cout<<n<<' ';
    int tmp=0;
    rep(i,n.size()){
        tmp*=2;
        tmp+=n[i]-'0';
        tmp%=p;
    }
    // cout<<tmp<<endl;
    string m;
    while(tmp>0){
        m+=tmp%2+'0';
        tmp/=2;
    }
    reverse(m.begin(),m.end());
    return 1+f(m);
}

int N;
string X;

int main(){
    cin>>N>>X;

    string y;
    rep(i,N){
        y=X;
        y[i]=y[i]=='0'?'1':'0';
        //cout<<y<<endl;
        cout<<f(y)<<endl;
    }
    
    return 0;
}