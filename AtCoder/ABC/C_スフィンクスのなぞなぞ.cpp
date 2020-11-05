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

int N,M;

int main(){
    cin>>N>>M;

    int i,j,k;
    j=min(4*N-M,-2*N+M);
    i=(4*N-M-j)/2;
    k=(-2*N+M-j)/2;
    if(i<0 || j<0 || k<0){
        i=j=k=-1;
    }

    cout<<i<<' '<<j<<' '<<k<<endl;
}