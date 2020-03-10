//貪欲法

#include <iostream>
#include <algorithm>
using namespace std;

int N;
char* S;
char* T;

int main(){
    cin>>N;
    cin>>S;
    
    int a=0;
    int b=N-2;
    while(a<=b){
        bool left=true;
        for(int i=a;i<=b;i++){
            if(S[i]<S[b-i+a]){
                left=true;
                break;
            }else if(S[i]>S[b-i+a]){
                left=false;
                break;
            }
        }

        if(left) T+=S[a++];
        else     T+=S[b--];
    }

    cout<<T;
}