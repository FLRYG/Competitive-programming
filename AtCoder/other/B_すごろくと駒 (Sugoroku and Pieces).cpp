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

int N,M;
int X[101];
int A[101];

int main(){
    cin>>N;
    repn(i,N) cin>>X[i];
    cin>>M;
    repn(i,M) cin>>A[i];

    repn(i,M){
        if(A[i]==N && X[A[i]]<2019 
        || X[A[i]]+1<X[A[i]+1]){
            X[A[i]]++;
        }
    }

    repn(i,N) cout<<X[i]<<endl;
    
    return 0;
}