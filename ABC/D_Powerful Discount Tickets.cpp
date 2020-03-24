#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

long N,M;
priority_queue<long> A;
long coupon[100001];

int main(){
    cin>>N>>M;
    long ans=0;
    rep(i,N){
        long x;
        cin>>x;
        A.push(x);
        ans+=x;
    }

    rep(i,M){
        long t=A.top();
        A.pop();
        A.push(t/2);
        ans-=t;
        ans+=t/2;
    }

    cout<<ans<<endl;
}