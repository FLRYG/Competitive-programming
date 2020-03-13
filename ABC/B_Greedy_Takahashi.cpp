#include <iostream>
using namespace std;

long A,B,K;

int main(){
    cin>>A>>B>>K;

    if(K<A){
        A=A-K;
    }else{
        B=B-(K-A);
        A=0;
    }

    if(B<0){
        B=0;
    }

    cout<<A<<' '<<B;
}