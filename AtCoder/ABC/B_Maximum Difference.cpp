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
using namespace std;
typedef long long ll;

int N;
int A[100];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    int sup=0,inf=1001001001;
    rep(i,N){
        if(sup<A[i]) sup=A[i];
        if(A[i]<inf) inf=A[i];
    }

    int ans=sup-inf;
    cout<<ans<<endl;
}