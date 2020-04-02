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

string S;

int main(){
    cin>>S;

    int ans=1001001001;
    rep(i,S.size()-2){
        string t;
        rep(j,3) t+=S[i+j];
        int n=atoi(t.c_str());
        ans=min(ans,abs(n-753));
    }

    cout<<ans<<endl;
}