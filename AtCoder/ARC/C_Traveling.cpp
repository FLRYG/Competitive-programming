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
int t[100001];
int x[100001];
int y[100001];

int main(){
    cin>>N;
    repn(i,N) cin>>t[i]>>x[i]>>y[i];

    repn(i,N){
        int T=t[i]-t[i-1];
        int d=abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
        if(!(T>=d && (T-d)%2==0)){
            cout<<"No"<<endl;
            return 0;
        }
    }

    cout<<"Yes"<<endl;
    
    return 0;
}