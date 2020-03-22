#include <iostream>
#include <cmath>
using namespace std;

long N;

int main(){
    cin>>N;

    long k=1;
    long i,j;
    long ans=100100100100100100;
    while(k<=1000000){
        if(N%k==0){
            i=k;
            j=N/k;
            if(i+j<ans){
                ans=i+j;
            }
        }
        k++;
    }

    ans-=2;

    cout<<ans<<endl;
}