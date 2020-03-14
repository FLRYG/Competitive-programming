#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int N;
char a='a';
char* s;

void fan(int n){

}

int main(){
    cin>>N;
    s=new char[N];

    for(int i=0;i<N;i++){
        s[i]='a';
    }
    cout<<s<<endl;

    for(int i=N-1;i>0;i++){
        fan(i);
    }

    

    delete[] s;
}