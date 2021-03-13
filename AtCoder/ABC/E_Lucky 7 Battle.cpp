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
string S,X;
vector<vector<int>> chk;
vector<vector<int>> bo;

int f(int n, int x){
    if(n==N){
        if(x==0) return true;
        else return  false;
    }
    if(chk[n][x]) return bo[n][x];
    chk[n][x]=true;
    int a=(x*10+(S[n]-'0'))%7;
    int b=x*10%7;
    if(X[n]=='T'){
        bo[n][x]=f(n+1,a)|f(n+1,b);
    }else{
        bo[n][x]=f(n+1,a)&f(n+1,b);
    }
    return bo[n][x];
}

int main(){
    cin>>N>>S>>X;
    
    chk=vector<vector<int>>(N,vector<int>(7,false));
    bo=vector<vector<int>>(N,vector<int>(7));

    if(f(0,0)) cout<<"Takahashi"<<endl;
    else cout<<"Aoki"<<endl;

    return 0;
}