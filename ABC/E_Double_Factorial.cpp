#include <iostream>
using namespace std;

long N;

int main(){
    cin>>N;

    if(N%2==1){
        cout<<0;
        return 0;
    }

    N/=2;

    //long count=1;
    long ans=0;
    do{
        ans+=N/=5;
    }while(N!=0);
    

    cout<<ans;
}