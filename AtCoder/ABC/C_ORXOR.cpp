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
int const INF=2001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
int A[20];

int f(int k, int x){
    if(k==N){
        return x;
    }
    int y=0;
    int res=INF;
    for(int i=k;i<N;i++){
        y|=A[i];
        res=min(res,f(i+1,x^y));
    }
    return res;
}

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    cout<<f(0,0)<<endl;
    
    return 0;
}