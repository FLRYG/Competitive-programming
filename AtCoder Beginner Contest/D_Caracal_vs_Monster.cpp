#include <iostream>
using namespace std;

long f(long h){
    if(h==1){
        return 1;
    }else{
        return 1+2*f(h/2);
    }
}

int main(){
    long H;
    cin>>H;

    cout<<f(H);
}