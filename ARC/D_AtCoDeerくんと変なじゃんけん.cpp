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

string S;
int N;

int main(){
    cin>>S;
    N=S.size();

    int g=0, p=0;
    rep(i,N){
        if(S[i]=='g') g++;
        if(S[i]=='p') p++;
    }

    int ans=g-p;
    if(ans>0) ans/=2;
    cout<<ans<<endl;
}