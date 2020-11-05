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
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int txa,tya;
int txb,tyb;
int T,V;
int n;
int x[1000], y[1000];

int main(){
    cin>>txa>>tya;
    cin>>txb>>tyb;
    cin>>T>>V>>n;
    rep(i,n) cin>>x[i]>>y[i];

    string ans="NO";
    rep(i,n){
        double d=0;
        d+=sqrt((txa-x[i])*(txa-x[i])+(tya-y[i])*(tya-y[i]));
        d+=sqrt((txb-x[i])*(txb-x[i])+(tyb-y[i])*(tyb-y[i]));
        if(d<=T*V){
            ans="YES";
            break;
        }
    }

    cout<<ans<<endl;
}