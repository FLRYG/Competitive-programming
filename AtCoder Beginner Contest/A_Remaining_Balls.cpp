#include <iostream>
using namespace std;

int main(){
    string S,T,U;
    int A,B;
    std::cin>>S>>T;
    std::cin>>A>>B;
    std::cin>>U;

    if(S==U){
        A--;
    }else{
        B--;
    }

    std::cout<<A<<' '<<B;
}