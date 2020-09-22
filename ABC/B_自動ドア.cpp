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

int N,T;
int A[100000];

int main(){
    cin>>N>>T;
    rep(i,N) cin>>A[i];

    int l,r;
    
}

/*
int N,T;
int A[1000002];

int main(){
    cin>>N>>T;
    rep(i,N){
        int a;
        cin>>a;
        A[a]++;
        A[min(a+T,1000001)]--;
    }
    int ans=0;
    int last=0;
    repn(i,1000000){
        A[i]+=A[i-1];
        if(A[i]>0){
            //cout<<i<<endl;
            ans++;
            last=i;
        }
    }
    //cout<<ans<<endl;
    if(A[1000001]>0){
        ans+=T-(1000000-A[N-1]);
    }

    cout<<ans<<endl;
}
*/