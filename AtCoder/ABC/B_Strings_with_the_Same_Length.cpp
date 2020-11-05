#include <iostream>
#include <string>
using namespace std;

int N;
string S,T;

int main(){
    cin>>N;
    cin>>S>>T;

    string ans;
    for(int i=0;i<N;i++){
        ans+=S[i];
        ans+=T[i];
    }

    cout<<ans<<endl;
}