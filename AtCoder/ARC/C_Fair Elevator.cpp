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

int N;
int A[100];
int B[100];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i]>>B[i];

    rep(i,N){
        if(A[i]>0 && B[i]>0 && A[i]>=B[i]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    
    vector<int> v(2*N+1);
    rep(i,N){
        if(A[i]==-1) continue;
        if(v[A[i]]==0) v[A[i]]=1;
        else{
            cout<<"No"<<endl;
            return 0;
        }
    }
    rep(i,N){
        if(B[i]==-1) continue;
        if(v[B[i]]==0) v[B[i]]=-1;
        else{
            cout<<"No"<<endl;
            return 0;
        }
    }

    vector<
}