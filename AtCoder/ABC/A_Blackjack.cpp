#include <iostream>
using namespace std;

int A,B,C;

int main(){
    cin>>A>>B>>C;

    int ans=A+B+C;

    if(ans>=22){
        cout<<"bust";
    }else{
        cout<<"win";
    }
}