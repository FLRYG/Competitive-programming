#include <iostream>
#include <algorithm>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int N,K;
int H[100000];

int main(){
    int ans=0;
    cin>>N>>K;
    rep(i,N){
        cin>>H[i];
        if(H[i]>=K){
            ans++;
        }
    }

    cout<<ans<<endl;
}