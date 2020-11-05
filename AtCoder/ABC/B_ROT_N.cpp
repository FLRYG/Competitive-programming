#include <iostream>
#include <string>
using namespace std;

int N;
string S;

int main(){
    cin>>N>>S;

    for(int i=0;i<S.size();i++){
        if(S[i]+N<='Z'){
            S[i]+=N;
        }else{
            S[i]='A'+S[i]+N-'Z'-1;
        }
    }

    cout<<S<<endl;
}