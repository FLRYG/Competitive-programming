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

string X;

int main(){
    cin>>X;

    int ans=0;
    int s=0;
    rep(i,X.size()){
        if(X[i]=='S') s++;
        else if(s>0) s--;
        else ans++;
    }
    ans+=s;

    cout<<ans<<endl;
}