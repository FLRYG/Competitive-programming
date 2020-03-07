#include <iostream>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int N=a>b?a:b;
    int X=a<b?a:b;

    for(int i=0;i<N;i++){
        cout<<X;
    }
}