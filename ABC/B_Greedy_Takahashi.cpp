#include <iostream>
using namespace std;

long A,B,K;

int main(){
    cin>>A>>B>>K;

    for(long i=0;i<K;i++){
        if(A>=1){
            A--;
        }else if(B>=1){
            B--;
        }else{
            break;
        }
    }

    cout<<A<<' '<<B;
}