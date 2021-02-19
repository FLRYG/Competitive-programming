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
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=2147483647;
ll const LINF=9223372036854775807;
ll const MOD=1000000007;

int N;

int main(){
    cin>>N;

    vector<P> ans(N+1);
    repn(i,N){
        int a,b;
        if(2*i<=N) a=2*i;
        else a=1;
        if(2*i+1<=N) b=2*i+1;
        else b=1;
        cout<<i<<": "<<a<<' '<<b<<endl; 
    }
    
    return 0;
}