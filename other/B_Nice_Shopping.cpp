#include <iostream>
using namespace std;

template <class T>
inline void swapa(T& a,T& b);
template <class T>
void sort(T* x,int left,int right);

template <class T>
inline void swapa(T& a,T& b){
    T tmp=a;
    a=b;
    b=tmp;
}

template <class T>
void sort(T* x,int left,int right){
    if(right-left<=1) return;
    int pivod=x[(right+left)/2];

    swapa(x[(right+left)/2],x[right-1]);
    int i=left;
    for(int j=left;j<right-1;j++){
        if(x[j]<pivod){
            swapa(x[i++],x[j]);
        }
    }
    swapa(x[i],x[right-1]);

    sort(x,left,i);
    sort(x,i+1,right);
}

int min(int a[],int begin,int end){
    int min=100100100;
    for(int i=begin;i<end;i++){
        if(a[i]<min) min=a[i];
    }
    return min;
}

int main(){
    int A,B,M;
    cin>>A>>B>>M;
    int a[100100];
    int b[100100];
    for(int i=1;i<=A;i++){
        cin>>a[i];
    }
    for(int j=1;j<=B;j++){
        cin>>b[j];
    }
    int x[100100];
    int y[100100];
    int c[100100];
    int coupon[100100];
    for(int i=1;i<=M;i++){
        cin>>x[i]>>y[i]>>c[i];
        coupon[i]=a[x[i]]+b[y[i]]-c[i];
    }

    int aa=min(a,1,A+1);
    int bb=min(b,1,B+1);
    int co=min(coupon,1,M+1);

    if(aa+bb>co){
        cout<<co<<endl;
    }else{
        cout<<aa+bb<<endl;
    }
}