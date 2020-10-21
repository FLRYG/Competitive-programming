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

string W;

int main(){
    cin>>W;

    string ans;
    rep(i,W.size()){
        if(W[i]!='a' && W[i]!='i' && W[i]!='u' && W[i]!='e'
        && W[i]!='o'){
            ans+=W[i];
        }
    }

    cout<<ans<<endl;
}