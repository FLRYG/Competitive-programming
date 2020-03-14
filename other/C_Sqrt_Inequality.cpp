#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long a,b,c;

int main(){
    cin>>a>>b>>c;

    if(c-a-b<0){
        cout<<"No";
    }else if(a*a+b*b+c*c-2*a*b-2*b*c-2*c*a>0){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}