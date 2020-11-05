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

int C;
int N[100],M[100],L[100];

int main(){
    cin>>C;
    rep(i,C) cin>>N[i]>>M[i]>>L[i];

    int n,m,l;
    rep(i,C){
        n=N[i];
        m=M[i];
        l=L[i];
        N[i]=max(n,max(m,l));
        L[i]=min(n,min(m,l));
        M[i]=n+m+l-N[i]-L[i];
    }
    n=0, m=0, l=0;
    rep(i,C){
        if(N[i]>n) n=N[i];
        if(M[i]>m) m=M[i];
        if(L[i]>l) l=L[i];
    }

    int ans=n*m*l;
    cout<<ans<<endl;
}