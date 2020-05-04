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
using namespace std;
typedef long long ll;

int N,M,Q;
int a[50],b[50],c[50],d[50];
int ans=0;

void dfs(vector<int> A){
    if(A.size()==N+1){
        int res=0;
        rep(i,Q){
            if(A[b[i]]-A[a[i]]==c[i]){
                res+=d[i];
            }
        }
        ans=max(ans,res);
        return;
    }
    A.push_back(A.back());
    while(A.back()<=M){
        dfs(A);
        A.back()++;
    }
}

int main(){
    cin>>N>>M>>Q;
    rep(i,Q) cin>>a[i]>>b[i]>>c[i]>>d[i];

    dfs(vector<int>(1,1));

    cout<<ans<<endl;
}