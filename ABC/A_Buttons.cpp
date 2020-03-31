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

int A,B;

int main(){
    cin>>A>>B;

    int ans=max(A+B,max(A+A-1,B+B-1));

    cout<<ans<<endl;
}