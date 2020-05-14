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

int N;
int B[21];
vector<int> c[21];

int dfs(int x){
    if(c[x].size()==0) return 1;
    int maxi=0, mini=1001001001;
    rep(i,c[x].size()){
        int m=dfs(c[x][i]);
        if(m>maxi) maxi=m;
        if(m<mini) mini=m;
    }
    return maxi+mini+1;
}

int main(){
    cin>>N;
    for(int i=2;i<=N;i++) cin>>B[i];

    for(int i=2;i<=N;i++){
        c[B[i]].push_back(i);
    }

    int ans=dfs(1);
    cout<<ans<<endl;
}