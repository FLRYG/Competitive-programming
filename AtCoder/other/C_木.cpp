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

int N;
vector<int> v[100000];
int chk[100000];

int main(){
    cin>>N;
    rep(i,N-1){
        int a,b;
        cin>>a>>b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }

    vector<int> ans;
    priority_queue<int,vector<int>,greater<int>> q;
    q.push(0);
    chk[0]=true;
    while(!q.empty()){
        int n=q.top(); q.pop();
        ans.push_back(n);
        repr(e,v[n]){
            if(chk[e]) continue;
            q.push(e);
            chk[e]=true;
        }
    }

    rep(i,ans.size()-1) cout<<(ans[i]+1)<<' ';
    cout<<(ans[N-1]+1)<<endl;
}