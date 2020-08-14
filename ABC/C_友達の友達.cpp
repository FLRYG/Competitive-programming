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
//ll const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

int N,M;
int A[11];
int B[11];

int main(){
    cin>>N>>M;
    repn(i,M) cin>>A[i]>>B[i];

    vector<int> G[11];
    repn(i,M){
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    repn(i,N){
        
    }
}