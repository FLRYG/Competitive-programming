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

int N,A,B;

int main(){
    cin>>N>>A>>B;

    int ans=0;
    rep(i,N){
        string s;
        int d;
        cin>>s>>d;
        if(d<A) d=A;
        if(d>B) d=B;
        if(s=="East") ans+=d;
        else ans-=d;
    }

    if(ans==0){
        cout<<0<<endl;
    }else if(ans<0){
        cout<<"West "<<-ans<<endl;
    }else{
        cout<<"East "<<ans<<endl;
    }
}