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
typedef pair<int,int> P;

int N;
int s[100000];
int Q;
int k[100000];
P cnt[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>s[i];
    cin>>Q;
    rep(i,Q) cin>>k[i];
    sort(s,s+N,greater<int>());

    rep(i,Q){
        int ans;
        ans=s[k[i]]+1;
        if(s[k[i]]==0 || k[i]>=N) ans=0;
        cout<<ans<<endl;
    }
}