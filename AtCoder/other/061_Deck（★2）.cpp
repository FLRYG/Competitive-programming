#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <chrono>
#include <random>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
// typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int Q;

int main(){
    cin>>Q;

    int C=100050;
    int l=C, r=C+1;
    vector<int> v(200100,0);
    while(Q--){
        int t,x;
        cin>>t>>x;
        if(t==1) v[l--]=x;
        else if(t==2) v[r++]=x;
        else cout<<v[l+x]<<endl;
    }
    
    return 0;
}