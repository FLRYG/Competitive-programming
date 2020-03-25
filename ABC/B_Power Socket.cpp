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

int A,B;

int main(){
    cin>>A>>B;

    int sum=1;
    int ans=0;
    while(sum<B){
        sum+=A-1;
        ans++;
    }

    cout<<ans<<endl;
}