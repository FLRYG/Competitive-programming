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

int P,Q,R;

int main(){
    cin>>P>>Q>>R;

    int ans=min(P+Q,min(Q+R,R+P));

    cout<<ans<<endl;
}