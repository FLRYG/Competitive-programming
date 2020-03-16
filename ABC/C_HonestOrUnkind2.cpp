#include <iostream>
using namespace std;

int N;
int A[15];
int x[15][15];
int y[15][15];

int pow2(int n){
    if(n==0){
        return 1;
    }else{
        return 2*pow2(n-1);
    }
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
        for(int j=0;j<N;j++){
            cin>>x[i][j]>>y[i][j];
        }
    }

    int all=pow2(N);
    for(int i=0;i<all;i++){
        for(int j=0;j<N;j++){
            int honest
            for(int k=0;k<A[i];k++){

            }
        }
    }
}