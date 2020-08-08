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
typedef long double ld;
ll const MOD=1000000007;

int A,B;

int main(){
    cin>>A>>B;

    int ans=0;
    ans+=B/4-(A-1)/4;
    ans-=B/100-(A-1)/100;
    ans+=B/400-(A-1)/400;

    cout<<ans<<endl;
}