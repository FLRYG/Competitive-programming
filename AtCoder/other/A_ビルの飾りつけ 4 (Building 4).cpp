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
int A[1000000];
int B[1000000];

int main(){
    cin>>N;
    rep(i,2*N) cin>>A[i];
    rep(i,2*N) cin>>B[i];

    string ans;
    vector<int> v(N);
    rep(i,N){
        if(A[i]<B[i]){
            v[i]=A[i];
            ans+='A';
        }else{
            v[i]=B[i];
            ans+='B';
        }
    }

    rep(i,N-1){
        if(v[i]>v[i+1])
    }
    
    return 0;
}