#include <iostream>

int main(){
    int N;
    int* A;
    std::cin>>N;
    A=new int[N];
    for(int i=0;i<N;i++){
        std::cin>>A[i];
    }

    bool b=true;
    for(int i=0;i<N;i++){
        if(A[i]%2==0){
            if(!(A[i]%3==0||A[i]%5==0)){
                b=false;
                break;
            }
        }
    }

    if(b){
        std::cout<<"APPROVED";
    }else{
       std::cout<<"DENIED"; 
    }

    delete[] A;
}