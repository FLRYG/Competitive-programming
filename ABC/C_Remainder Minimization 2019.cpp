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

const int MOD=2019;
int L,R;

int main(){
    cin>>L>>R;

    int k=R-L+1;
    if(k>=2019){
        cout<<0<<endl;
        return 0;
    }

    int ans=MOD-1;
    for(int i=L;i<=R-1;i++){
        for(int j=i+1;j<=R;j++){
            if((i%MOD)*(j%MOD)%MOD<ans) ans=(i%MOD)*(j%MOD)%MOD;
        }
    }

    cout<<ans<<endl;
}