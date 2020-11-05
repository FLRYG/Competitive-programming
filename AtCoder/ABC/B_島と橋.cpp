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
int a[101];
int sum[101];
int m;

int main(){
    cin>>N;
    repn(i,N){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    if(sum[N]%N!=0){
        cout<<-1<<endl;
        return 0;
    }
    m=sum[N]/N;

    int ans=0;
    repn(i,N-1){
        if(m*i!=sum[i]) ans++;
    }

    cout<<ans<<endl;
}