#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int D;

int main(){
    cin>>D;

    string ans="Christmas";
    for(int i=0;i<25-D;i++){
        ans+=" Eve";
    }

    cout<<ans<<endl;
}