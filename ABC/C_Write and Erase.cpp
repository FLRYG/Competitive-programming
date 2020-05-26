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
map<int,int> m;

int main(){
    cin>>N;
    rep(i,N){
        int a;
        cin>>a;
        m[a]=m[a]^1;
    }

    int ans=0;
    repr(e,m){
        if(e.second) ans++;
    }

    cout<<ans<<endl;
}