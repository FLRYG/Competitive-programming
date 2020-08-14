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
typedef pair<int,int> P;
//ll const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

int H,W,D;
int A[301][301];
int Q;
int L[100001];
int R[100001];
P memo[90001];

int main(){
    cin>>H>>W>>D;
    repn(i,H) repn(j,W) cin>>A[i][j];
    cin>>Q;
    repn(i,Q) cin>>L[i]>>R[i];

    repn(i,H) repn(j,W) memo[A[i][j]]=P(i,j);

    repn(i,Q){
        int ans=0;
        for(int j=L[i];j<R[i];j+=D){
            ans+=abs(memo[j].first-memo[j+D].first)+abs(memo[j].second-memo[j+D].second);
        }
        cout<<ans<<endl;
    }
}