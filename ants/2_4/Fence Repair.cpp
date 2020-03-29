#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int N;
priority_queue<int,vector<int>,greater<int>> L;

int main(){
    cin>>N;
    rep(i,N){int x; cin>>x; L.push(x);}

    int ans=0;
    while(L.size()>1){
        int a=L.top(); L.pop();
        int b=L.top(); L.pop();

        ans+=a+b;
        L.push(a+b);
    }

    cout<<ans<<endl;
}