#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

ll N,A,B;

int main(){
    cin>>N>>A>>B;

    ll ans;
    if(!((A&1)^(B&1))){
        ans=(B-A)/2;
    }else{
        ans=min(A+(B-A)/2,(N-B+1)+((N-A)-(N-B+1))/2);
    }

    cout<<ans<<endl;
}