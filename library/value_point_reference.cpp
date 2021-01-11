#include <iostream>
using namespace std;

void value(int x){
    x+=1;
    cout<<"value"<<endl;
    cout<<"   x = "<<x<<endl;
    cout<<"  &x = "<<&x<<endl;
}

void pointer(int *x){
    *x+=1;
    cout<<"pointer"<<endl;
    cout<<"   x = "<<x<<endl;
    cout<<"  &x = "<<&x<<endl;
    cout<<"  *x = "<<*x<<endl;
    // cout<<"  &(*x) = "<<&(*x)<<endl;
    // cout<<"  *(&x) = "<<*(&x)<<endl;
}

void reference(int &x){
    x+=1;
    cout<<"pointer"<<endl;
    cout<<"   x = "<<x<<endl;
    cout<<"  &x = "<<&x<<endl;
}

int main(){
    int n=10;
    cout<<"main"<<endl;
    cout<<"   n = "<<n<<endl;
    cout<<"  &n = "<<&n<<endl;
    value(n);
    pointer(&n);
    reference(n);
}