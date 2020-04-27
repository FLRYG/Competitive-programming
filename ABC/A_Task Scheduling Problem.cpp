#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#include <map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int A[3];

int main(){
    rep(i,3) cin>>A[i];
    
    sort(A,A+3);

    int ans=0;
    rep(i,2) abs(ans+=A[i+1]-A[i]);

    cout<<ans<<endl;
}