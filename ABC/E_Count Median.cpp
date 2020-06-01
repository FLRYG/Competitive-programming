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
typedef pair<int,int> P;

int N;
int A[200000];
int B[200000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i]>>B[i];

    sort(A,A+N);
    sort(B,B+N,greater<int>());

    int ans;
    if(N&1){
        ans=abs(B[N/2]-A[N/2])+1;
    }else{
        
    }
    

    cout<<ans<<endl;
}