#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int N;
int L[2000];

int f(int begin,int end){
    
}

int main(){
    cin>>N;
    rep(i,N) cin>>L[i];

    sort(L,L+N);

    int ans=0;
    for(int i=N;i>=2;i--){
        for(int j=i-1;j>=1;j--){
            
        }
    }

    cout<<ans;
}