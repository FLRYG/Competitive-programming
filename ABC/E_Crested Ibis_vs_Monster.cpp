#include <iostream>
#include <list>
#include <vector>
using namespace std;

template <class T>
inline void swap(T& a,T& b);
template <class T>
void sort(T* x,int left,int right);

int H,N;
double* A;
double* B;
double* e;

int main(){
    
    cin>>H>>N;
    A=new double[N];
    B=new double[N];
    e=new double[N];
    for(int i=0;i<N;i++){
        cin>>A[i]>>B[i];
        e[i]=A[i]/B[i];
    }
    sort(e,0,sizeof(e)/sizeof(e[0]));

    int count=0;
    int i=1;
    while(H<=0){
        if(H/A[N-1]>=1){
            H-=floor(H/A[N-1])*A[N-1];
            count+=floor(H/A[N-1])*B[N-1];
        }
    }
    

    delete[] A,B,e;
}

template <class T>
inline void swap(T& a,T& b){
    T tmp=a;
    a=b;
    b=tmp;
}

template <class T>
void sort(T* x,int left,int right){
    if(right-left<=1) return;
    int pivod=x[(right+left)/2];

    swap(A[(right+left)/2],A[right-1]);
    swap(B[(right+left)/2],B[right-1]);
    swap(x[(right+left)/2],x[right-1]);
    int i=left;
    for(int j=left;j<right-1;j++){
        if(x[j]<pivod){
            swap(A[i],A[j]);
            swap(B[i],B[j]);
            swap(x[i++],x[j]);
        }
    }
    swap(A[i],A[right-1]);
    swap(B[i],B[right-1]);
    swap(x[i],x[right-1]);

    sort(x,left,i);
    sort(x,i+1,right);
}