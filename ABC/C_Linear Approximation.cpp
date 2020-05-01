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
using namespace std;
typedef long long ll;

ll N;
ll A[200000];

int main(){
    cin>>N;
    rep(i,N){
        cin>>A[i];
        A[i]-=i+1;
    }

    sort(A,A+N);

    ll b1,b2,b3;
    if(N%2==0){
        b1=(A[N/2]+A[N/2-1])/2;
        b2=b1-1;
        b3=b1+1;
    }else{
        b1=A[N/2];
        b2=b1-1;
        b3=b1+1;
    }

    ll ans1=0, ans2=0, ans3=0;
    rep(i,N){
        ans1+=abs(A[i]-b1);
        ans2+=abs(A[i]-b2);
        ans3+=abs(A[i]-b3);
    }

    ll ans=min(ans1,min(ans2,ans3));
    cout<<ans<<endl;
}