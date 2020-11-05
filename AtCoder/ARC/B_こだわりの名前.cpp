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
typedef pair<int,int> P;

string A;

int main(){
    cin>>A;

    int sum=0;
    rep(i,(A.size()+1)/2){
        if(A[i]!=A[A.size()-i-1]) sum++;
    }

    int ans=25*A.size();
    if(A.size()&1 && sum==0) ans-=25;
    if(sum==1) ans-=2;

    cout<<ans<<endl;
}