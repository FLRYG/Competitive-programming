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

string S;

int main(){
    cin>>S;

    int c0=0,c1=0;
    rep(i,S.size()){
        if(S[i]=='0') c0++;
        if(S[i]=='1') c1++;
    }

    int ans=2*min(c0,c1);
    cout<<ans<<endl;
}