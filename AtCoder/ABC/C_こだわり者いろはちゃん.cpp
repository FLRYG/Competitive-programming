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
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;
typedef long double ld;

int N,K;
int D[10];

int main(){
    cin>>N>>K;
    rep(i,K){
        int d;
        cin>>d;
        D[d]++;
    }

    int ans=N;
    while(true){
        int x=ans;
        bool flag=true;
        while(x>0){
            flag&=(D[x%10]+1)%2;
            x/=10;
        }
        if(flag) break;
        ans++;
    }

    cout<<ans<<endl;
}