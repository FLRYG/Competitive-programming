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

int N,T,A;
double H[1000];

int main(){
    cin>>N>>T>>A;
    rep(i,N) cin>>N;

    int ans,val=10000000;
    rep(i,N){
        int abst=abs(A-(T-H[i]*0.006));
        if(abst<val){
            val=abst;
            ans=i+1;
        }
    }

    cout<<ans<<endl;
}