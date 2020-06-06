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

int N;
string S;

int main(){
    cin>>N>>S;

    int r=0, g=0, b=0;
    rep(i,S.size()){
        if(S[i]=='R') r++;
        if(S[i]=='G') g++;
        if(S[i]=='B') b++;
    }
    int ans=(r&1)+(g&1)+(b&1);

    cout<<ans<<endl;
}