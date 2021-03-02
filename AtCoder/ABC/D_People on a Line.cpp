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
// typedef pair<P,int> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N,M;

int main(){
    cin>>N>>M;
    vector<vector<P>> G(N,vector<P>(0));
    rep(i,M){
        int l,r,d;
        cin>>l>>r>>d;
        l--, r--;
        G[l].push_back({r,d});
        G[r].push_back({l,-d});
    }

    vector<bool> chk(N,false);
    rep(i,N){
        if(chk[i]) continue;
        map<int,int> x;
        x[i]=0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int p=q.front(); q.pop();
            if(chk[p])continue;
            chk[p]=true;
            repr(e,G[p]){
                if(!chk[e.first]){
                    x[e.first]=x[p]+e.second;
                    q.push(e.first);
                }else{
                    if(x[p]+e.second!=x[e.first]){
                        cout<<"No"<<endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout<<"Yes"<<endl;
    
    return 0;
}