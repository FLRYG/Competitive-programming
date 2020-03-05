#include <iostream>
using namespace std;

int main(){
    char S[101];
    cin>>S;
    
    for(int i=0;S[i];i++){
        S[i]='x';
    }

    cout<<S;
}