#include <iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    int* P=new int[N];
    for(int i=0;i<N;i++){
        cin>>P[i];
    }

    int min=1001001001;
    int count=0;
    for(int i=0;i<N;i++){
        if(P[i]<=min){
            min=P[i];
            count++;
        }
    }

    cout<<count;
}