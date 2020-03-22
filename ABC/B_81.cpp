#include <iostream>
using namespace std;

int N;

int main(){
    cin>>N;

    for(int i=1;i<=9;i++){
        if(N%i==0 && N/i<=9){
            cout<<"Yes";
            return 0;
        }
    }

    cout<<"No";

}