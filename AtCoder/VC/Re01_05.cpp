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

int N,K;
int A[200000];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>A[i];

    int ok=0, ng=INF;
    while(ng-ok>1){
        // cout<<ok<<' '<<ng<<endl;
        int m=(ok+ng)/2;
        int cnt=0;
        rep(i,N){
            cnt+=(A[i]-1)/m;
        }
        if(cnt>K) ok=m;
        else ng=m;
    }

    cout<<ok+1<<endl;
    
    return 0;
}