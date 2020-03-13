#include <iostream>
using namespace std;

void my_next_permutation(int* array,int n){
    int I,J;
    for(int i=n-1;i>0;i++){
        if(array[i]>array[i-1]){
            I=i;
            for(int j=n-1;j>=0;j++){
                if(array[i]>array[j]){
                    J=j;
                }
            }
        }
    }
}