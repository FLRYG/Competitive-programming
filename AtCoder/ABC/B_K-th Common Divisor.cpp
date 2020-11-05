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

int A,B,K;

int main(){
    cin>>A>>B>>K;

    int ans;
    for(int i=min(A,B);i>=1;i--){
        if(A%i==0 && B%i==0){
            K--;
            if(K==0){
                ans=i;
                break;
            }
        }
    }

    cout<<ans<<endl;
}