#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

long N;
long A[200001];
long C[200001];

int main(){
    cin>>N;
    for(long i=1;i<=N;i++){
        cin>>A[i];
        C[A[i]]++;
    }

    //for(long i=1;i<=N;i++){
    //    cout<<C[i]<<endl;
    //}

    long sum=0;
    for(long i=1;i<=N;i++){
        if(C[i]>=2){
            sum+=C[i]*(C[i]-1)/2;
        }
    }
    //cout<<sum<<endl;

    long ans;
    for(long i=1;i<=N;i++){
        if(C[A[i]]>=2){
            ans=sum-(C[A[i]]-1);
        }else{
            ans=sum;
        }
        cout<<ans<<endl;
    }
}