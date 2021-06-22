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

int M,R;

int main(){
    cin>>M>>R;

    int ans=0;
    vector<int> chk(10*M,true);
    queue<IP> q;
    q.push({0,{0,0}});
    while(!q.empty()){
        IP p=q.front(); q.pop();
        int c=p.first;
        int pos=p.second.first;
        int r=p.second.second;
        if(!chk[pos*M+r]) continue;
        // cout<<c<<' '<<pos<<' '<<r<<endl;
        if(r==R){
            ans=p.first;
            break;
        }
        chk[pos*M+r]=false;
        q.push({c+1,{pos,(r*10+pos)%M}});
        if(pos==0){
            q.push({c+1,{1,r}});
        }else{
            if(pos==1) q.push({c+1,{0,r}});
            if(pos%3!=0) q.push({c+1,{pos+1,r}});
            if(pos%3!=1) q.push({c+1,{pos-1,r}});
            if(pos<=6) q.push({c+1,{pos+3,r}});
            if(pos>=4) q.push({c+1,{pos-3,r}});
        }
    }

    cout<<ans<<endl;

    return 0;
}