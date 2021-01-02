#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
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
int x[1000];
int y[1000];

int main(){
    cin>>N;
    rep(i,N) cin>>x[i]>>y[i];
    
    int ans=0;
    rep(i,N-1){
        for(int j=i+1;j<N;j++){
            if(abs(x[i]-x[j])>=abs(y[i]-y[j])) ans++;
        }
    }

    cout<<ans<<endl;
    
    return 0;
}