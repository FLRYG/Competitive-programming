#include <iostream>
#include <algorithm>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int N,M;

int main(){
    cin>>N>>M;

    int ans;
    if(N<=1){
        ans+=0;
    }else{
        ans+=N*(N-1)/2;
    }

    if(M<=1){
        ans+=0;
    }else{
        ans+=M*(M-1)/2;
    }

    cout<<ans<<endl;
}