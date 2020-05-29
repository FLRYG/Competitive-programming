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

int R,C,D;
int A[1000][1000];
int cnt[1000][1000];

int main(){
    cin>>R>>C>>D;
    rep(i,R) rep(j,C){
        cin>>A[i][j];
        int k=0;
        if(i==0 && j==0) continue;
        if(i==0){
            cnt[i][j]=cnt[i][j-1]+1;
        }else if(j==0){
            cnt[i][j]=cnt[i-1][j]+1;
        }else{
            cnt[i][j]=1+min(cnt[i-1][j],cnt[i][j-1]);
        }
    }

    int ans=0;
    rep(i,R) rep(j,C){
        if(!((cnt[i][j]&1)^(D&1)) && cnt[i][j]<=D){
            ans=max(ans,A[i][j]);
        }
    }

    cout<<ans<<endl;
}