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

int H,W,A,B;

int f(int g, int i, int a, int b){
    if(i==H*W){
        if(a==0 && b==0) return 1;
        else return 0;
    }
    if(g>>i&1) return f(g,i+1,a,b);
    int res=0;
    res+=f(g|1<<i,i+1,a,b-1);
    if(i+W<H*W && !(g>>(i+W)&1)) res+=f(g|1<<i|1<<(i+W),i+1,a-1,b);
    if((i+1)%W && !(g>>(i+1)&1)) res+=f(g|1<<i|1<<(i+1),i+1,a-1,b);
    return res;
}

int main(){
    cin>>H>>W>>A>>B;

    int ans=f(0,0,A,B);

    cout<<ans<<endl;
    
    return 0;
}