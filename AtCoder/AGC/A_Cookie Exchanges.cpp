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
//typedef pair<int,int> P;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll A,B,C;

int main(){
    cin>>A>>B>>C;

    if(A==B && B==C && ~A&1){
        cout<<-1<<endl;
        return 0;
    }

    int ans=0;
    while(~A&1 && ~B&1 && ~C&1){
        ll sum=A+B+C;
        A=(sum-A)/2;
        B=(sum-B)/2;
        C=(sum-C)/2;
        ans++;
    }

    cout<<ans<<endl;
}