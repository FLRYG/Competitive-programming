#include <iostream>
using namespace std;

int main(){
    long N,A,B;
    cin>>N>>A>>B;

    long sum=0;
    sum+=N/(A+B)*A;

    if(N%(A+B)>=A){
        sum+=A;
    }else{
        sum+=N%(A+B);
    }

    cout<<sum;

}