#include <iostream>

template <class T>
inline void swap(T& a,T& b);
template <class T>
void sort(T* x,int left,int right);

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

    swap(x[(right+left)/2],x[right-1]);
    int i=left;
    for(int j=left;j<right-1;j++){
        if(x[j]<pivod){
            swap(x[i++],x[j]);
        }
    }
    swap(x[i],x[right-1]);

    sort(x,left,i);
    sort(x,i+1,right);
}

int main(){
    int a[]={5,2,7,0,3,6,8,4,1,2,9};
    sort(a,0,sizeof(a)/sizeof(a[0]));
    for(auto x:a){
        std::cout<<x<<' ';
    }
    std::cout<<'\n';

    double b[]={2.4,3.7,7.9,0.4,7.1,9.6,4.3};
    sort(b,0,sizeof(b)/sizeof(b[0]));
    for(auto x:b){
        std::cout<<x<<' ';
    }
}