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
// typedef pair<int,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int popcount(string S){
    int res=0;
    rep(i,S.size()) res+=(S[i]-'0')&1;
    return res;
}

int f(string S){
    if(S=="0") return 0;
    int n=popcount(S);
    int x=0;
    // cout<<n<<endl;
    rep(i,S.size()){
        x=x*2+(S[i]-'0');
        x%=n;
    }
    string T;
    while(x>0){
        T+='0'+(x&1);
        x/=2;
    }
    reverse(T.begin(),T.end());
    if(T=="") T+='0';
    // cout<<"T "<<T<<endl;
    return 1+f(T);
}

int N;
string X;

int main(){
    cin>>N>>X;

    rep(i,N){
        string x=X;
        if(x[i]=='1') x[i]='0';
        else x[i]='1';
        // cout<<x<<endl;
        cout<<f(x)<<endl;
    }
    
    return 0;
}