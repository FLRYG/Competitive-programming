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
typedef pair<int,int> P;
typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int H,W,T;
char s[10][10];

int main(){
    cin>>H>>W>>T;
    rep(i,H) rep(j,W) cin>>s[i][j];
    int si, sj, gi, gj;
    rep(i,H) rep(j,W){
        if(s[i][j]=='S') si=i, sj=j;
        if(s[i][j]=='G') gi=i, gj=j;
    }

    int ok=1, ng=INF;
    while(ng-ok>1){
        int x=(ok+ng)/2;
        bool flag=false;
        priority_queue<IP,vector<IP>,greater<IP>> q;
        q.push(IP(0,{si,sj}));
        while(!q.empty()){
            IP p=q.top(); q.pop();
            if(p.second.first==gi && p.second.second==gj){
                if(p.first<=T) ok=x;
                else ng=x;
                break;
            }
            
        }
    }
    
    return 0;
}