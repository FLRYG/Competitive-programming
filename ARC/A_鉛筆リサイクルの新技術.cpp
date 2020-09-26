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
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int m,n,N;

int main(){
    cin>>m>>n>>N;

    int ans=0;
    int mul=0;
    int rem=0;
    do{
        ans+=N;
        mul=(N+rem)/m*n;
        rem=(N+rem)%m;
        N=mul;
    }while(N>0);

    cout<<ans<<endl;
}