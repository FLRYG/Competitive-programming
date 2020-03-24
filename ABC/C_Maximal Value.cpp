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

int N;
int B[100];

int main(){
    cin>>N;
    rep(i,N-1) cin>>B[i];

    B[N-1]=100100;
    int ans=B[0];
    rep(i,N-2){
        ans+=min(B[i],B[i+1]);
    }
    ans+=B[N-2];

    cout<<ans<<endl;
}