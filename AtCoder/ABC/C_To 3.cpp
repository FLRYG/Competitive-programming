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

string N;
int mod[3];

int main(){
    cin>>N;

    int val=0;
    rep(i,N.size()){
        val+=N[i]-'0';
        mod[(N[i]-'0')%3]++;
    }
    val%=3;

    int ans=-1;
    if(val==0) ans=0;
    else if(mod[val]>=1 && N.size()>=2) ans=1;
    else if(val==1 && mod[2]>=2 && N.size()>=3) ans=2;
    else if(val==2 && mod[1]>=2 && N.size()>=3) ans=2;

    cout<<ans<<endl;
    
    return 0;
}