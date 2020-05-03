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

int N,M;
int H[100000];
vector<int> R[100001];

int main(){
    cin>>N>>M;
    rep(i,N) cin>>H[i];
    rep(i,M){
        int a,b;
        cin>>a>>b;
        R[a].push_back(b);
        R[b].push_back(a);
    }

    int ans=0;
    repn(i,N){
        bool b=true;
        rep(j,R[i].size()){
            if(H[i-1]<=H[R[i][j]-1]) b=false;
        }
        if(b) ans++;
    }

    cout<<ans<<endl;
}