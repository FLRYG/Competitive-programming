#include <iostream>
#include <string>
using namespace std;

int N;
string S;

int main(){
    cin>>N;
    cin>>S;

    int ans=0;
    int i=0;
    for(int i=0;i<N-2;i++){
        if(S[i]=='A' && S[i+1]=='B' && S[i+2]=='C'){
            ans++;
        }
    }

    cout<<ans;
}