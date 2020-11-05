#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int N;
priority_queue<int> p;

int main(){
    cin>>N;
    rep(i,N){
        int x;
        cin>>x;
        p.push(x);
    }

    int ans=0;
    ans+=p.top()/2;
    p.pop();
    while(!p.empty()){
        ans+=p.top();
        p.pop();
    }

    cout<<ans<<endl;
}