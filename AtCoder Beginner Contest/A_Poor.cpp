#include <iostream>

int main(){
    int A,B,C;
    std::cin>>A>>B>>C;

    if((A==B&&B==C)||(A!=B&&B!=C&&C!=A)){
        std::cout<<"No";
    }else{
        std::cout<<"Yes";
    }
}