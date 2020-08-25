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
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
int A[100002];

int main(){
    cin>>N;
    repn(i,N) cin>>A[i];
    A[0]=0;
    A[N+1]=0;

    int sum=0;
    repn(i,N+1){
        sum+=abs(A[i]-A[i-1]);
    }

    repn(i,N){
        int ans=sum;
        ans-=abs(A[i-1]-A[i])+abs(A[i]-A[i+1]);
        ans+=abs(A[i-1]-A[i+1]);
        cout<<ans<<endl;
    }
}