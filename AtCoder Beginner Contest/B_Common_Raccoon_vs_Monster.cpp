#include <iostream>
using namespace std;

int main(){
    int H,N;
    int* A;
    cin>>H>>N;
    A=new int[N];
    int sum=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        sum+=A[i];
    }

    if(sum>=H){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}