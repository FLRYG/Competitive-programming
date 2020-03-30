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

int N,L;
priority_queue<int,vector<int>,greater<int>> x;

int main(){
    cin>>N>>L;

    int sum=N*L+N*(N+1)/2-N;
    int ans;
    if(L>=0){
        ans=sum-L;
    }else if(L<=-N){
        ans=sum-(L+N-1);
    }else{
        ans=sum;
    }

    cout<<ans<<endl;
}