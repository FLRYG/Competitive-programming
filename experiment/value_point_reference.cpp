#include <iostream>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
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
    cout<<"reference"<<endl;
    cout<<"   x = "<<x<<endl;
    cout<<"  &x = "<<&x<<endl;
}



void value(vector<int> v){
    rep(i,v.size()) v[i]+=1;
    cout<<"value"<<endl;
    cout<<"   v = ";
    rep(i,v.size()) cout<<v[i]<<' '; cout<<endl;
    cout<<"  &v = "<<&v<<endl;
}

void pointer(vector<int> *v){
    rep(i,v->size()) v->at(i)+=1;
    cout<<"pointer"<<endl;
    cout<<"   v = "<<v<<endl;
    cout<<"  &v = "<<&v<<endl;
    cout<<"  *v = ";
    rep(i,v->size()) cout<<v->at(i)<<' '; cout<<endl;
    // cout<<"  &(*v) = "<<&(*v)<<endl;
    // cout<<"  *(&v) = "<<*(&v)<<endl;
}

void reference(vector<int> &v){
    rep(i,v.size()) v[i]+=1;
    cout<<"reference"<<endl;
    cout<<"   v = ";
    rep(i,v.size()) cout<<v[i]<<' '; cout<<endl;
    cout<<"  &v = "<<&v<<endl;
}




int main(){
    int n=10;
    cout<<"\"int\""<<endl;
    cout<<"origin"<<endl;
    cout<<"   n = "<<n<<endl;
    cout<<"  &n = "<<&n<<endl;
    value(n);
    pointer(&n);
    reference(n);
    cout<<"origin"<<endl;
    cout<<"   n = "<<n<<endl;
    cout<<"  &n = "<<&n<<endl;

    cout<<endl;

    vector<int> v{0,1,2,3,4};
    cout<<"\"vector<int>\""<<endl;
    cout<<"origin"<<endl;
    cout<<"   v = ";
    rep(i,v.size()) cout<<v[i]<<' '; cout<<endl;
    cout<<"  &v = "<<&n<<endl;
    value(v);
    pointer(&v);
    reference(v);
    cout<<"origin"<<endl;
    cout<<"   v = ";
    rep(i,v.size()) cout<<v[i]<<' '; cout<<endl;
    cout<<"  &v = "<<&n<<endl;

    return 0;
}