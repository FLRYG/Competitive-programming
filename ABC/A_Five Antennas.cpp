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

int a,b,c,d,e,k;

int main(){
    cin>>a>>b>>c>>d>>e>>k;

    int pmax=max(a,max(max(b,c),max(d,e)));
    int pmin=min(a,min(min(b,c),min(d,e)));

    string ans;
    if(pmax-pmin<=k){
        ans="Yay!";
    }else{
        ans=":(";
    }

    cout<<ans<<endl;
}