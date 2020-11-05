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

const int MOD=10007;

int main(){
    int n;
    cin>>n;
    int a_3=0, a_2=0, a_1=1;

    rep(i,n-1){
        int a=(a_1+a_2+a_3)%MOD;
        a_3=a_2;
        a_2=a_1;
        a_1=a;
    }

    int ans=a_3;
    cout<<ans<<endl;
}