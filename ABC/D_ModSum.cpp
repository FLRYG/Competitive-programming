#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

ll N;

int main(){
    cin>>N;

    ll ans=N*(N-1)/2;

    cout<<ans<<endl;
}