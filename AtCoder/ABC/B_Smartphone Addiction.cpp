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
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N,M,T;
int A[1001];
int B[1001];

int main(){
    cin>>N>>M>>T;
    repn(i,M) cin>>A[i]>>B[i];

    int n=N;
    repn(i,M){
        n-=A[i]-B[i-1];
        if(n<=0){
            cout<<"No"<<endl;
            return 0;
        }
        n+=B[i]-A[i];
        n=min(n,N);
    }
    n-=T-B[M];
    if(n<=0){
        cout<<"No"<<endl;
        return 0;
    }

    cout<<"Yes"<<endl;
    
    return 0;
}