#include <iostream>
#include <map>
#include <string>

int main(){
    int N;
    char* S;
    std::cin>>N;
    S=new char[N];
    for(int i=0;i<N;i++){
        std::cin>>S[i];
        //std::cout<<S[i];
    }

    delete[] S;
}