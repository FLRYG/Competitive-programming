#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int N,M;
int X[100000];
priority_queue<int> dis; 

int main(){
    cin>>N>>M;
    rep(i,M) cin>>X[i];
    if(N>=M){
        cout<<0<<endl;
        return 0;
    }

    sort(X,X+M);

    int ans=X[M-1]-X[0];
    rep(i,M-1){
        dis.push(X[i+1]-X[i]);
    }
    rep(i,N-1){
        ans-=dis.top();
        dis.pop();
    }

    cout<<ans<<endl;
}