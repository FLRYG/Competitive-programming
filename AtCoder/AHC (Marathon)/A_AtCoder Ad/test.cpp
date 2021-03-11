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

struct SQ{
    int a,b,c,d;
    SQ(int _a, int _b, int _c, int _d): a(_a), b(_b), c(_c), d(_d){}
    ~SQ(){}
    SQ operator+=(const SQ &x){
        a+=x.a; b+=x.b; c+=x.c; d+=x.d;
        return (*this); 
    }
    SQ operator+(const SQ &x){ return (*this)+=x; }
    
};

int main(){
    int N=100000000;
    vector<int> cnt(N+1,0);

    repn(i,N){
        for(int j=i;j<=N;j+=i){
            cnt[j]++;
        }
    }

    int ans=0;
    int val;
    repn(i,N){
        if(cnt[i]>ans){
            ans=cnt[i];
            val=i;
        }
    }

    cout<<val<<' '<<ans<<endl;

    return 0;
}