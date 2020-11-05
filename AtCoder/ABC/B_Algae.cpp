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

int r,D,x;

int main(){
    cin>>r>>D>>x;

    rep(i,10){
        x=r*x-D;
        cout<<x<<endl;
    }
}