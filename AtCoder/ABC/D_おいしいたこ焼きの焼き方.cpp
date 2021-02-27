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
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N,Q;
int D[51][51];

int main(){
    cin>>N;
    repn(i,N) repn(j,N) cin>>D[i][j];
    repn(i,N) repn(j,N){
        D[i][j]+=D[i-1][j]+D[i][j-1]-D[i-1][j-1];
    }
    cin>>Q;

    vector<int> ans(Q);
    rep(q,Q){
        int P;
        cin>>P;
        int res=0;
        repn(i,50){
            int a=min(i,N), b=min(P/i,N);
            if(a==0 || b==0) continue;
            for(int i=a;i<=N;i++){
                for(int j=b;j<=N;j++){
                    res=max(res,D[i][j]-D[i-a][j]-D[i][j-b]+D[i-a][j-b]);
                    res=max(res,D[j][i]-D[j][i-a]-D[j-b][i]+D[j-b][i-a]);
                }
            }
        }
        ans[q]=res;
    }

    rep(i,Q) cout<<ans[i]<<endl;
    
    return 0;
}