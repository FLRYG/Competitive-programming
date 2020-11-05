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

int N,T;
int A[100000], B[100000];
priority_queue<int> diff;

int main(){
    cin>>N>>T;
    rep(i,N) cin>>A[i]>>B[i];

    int sum=0;
    rep(i,N){
        sum+=A[i];
        diff.push(A[i]-B[i]);
    }

    int ans=0;
    rep(i,N){
        if(sum<=T){
            cout<<ans<<endl;
            return 0;
        }
        int d=diff.top();
        diff.pop();
        sum-=d;
        ans++;
    }
    if(sum<=T){
        cout<<ans<<endl;
        return 0;
    }

    cout<<-1<<endl;
}