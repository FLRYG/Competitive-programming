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
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
int a[100];

int main(){
    cin>>N;
    rep(i,N) cin>>a[i];

    int m=0;
    rep(i,N) m+=a[i];
    rep(i,N) a[i]*=N;

    int ans;
    int diff=INF;
    rep(i,N){
        if(abs(a[i]-m)<diff){
            ans=i;
            diff=abs(a[i]-m);
        }
    }

    cout<<ans<<endl;
    
    return 0;
}