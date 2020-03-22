#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int N;
int d[50];

int main(){
    cin>>N;
    rep(i,N) cin>>d[i];

    int ans=0;
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            ans+=d[i]*d[j];
        }
    }

    cout<<ans;
}