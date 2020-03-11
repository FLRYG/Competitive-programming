//貪欲法

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N;
string S;
string ans;

int main(){
    cin>>N;
    cin>>S;
    
    int a=0;
    int b=N-1;
    while(a<=b){
        bool left=true;
        for(int i=0;a+i<=b;i++){
            if(S[a+i]<S[b-i]){
                left=true;
                break;
            }else if(S[a+i]>S[b-i]){
                left=false;
                break;
            }
        }

        if(left) ans+=S[a++];
        else     ans+=S[b--];
    }

    cout<<ans;
}