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
priority_queue<int,vector<int>,greater<int>> dis; 

int main(){
    cin>>N>>M;
    rep(i,M) cin>>X[i];

    sort(X,X+M);

    rep(i,M-1){
        dis.push(X[i+1]-X[i]);
    }

    int ans=0;
    rep(i,(N-1)){
        ans+=dis.top();
        dis.pop();
    }

    cout<<ans<<endl;
}