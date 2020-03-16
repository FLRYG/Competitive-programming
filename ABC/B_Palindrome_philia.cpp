#include <iostream>
#include <string>
using namespace std;

string S;

int main(){
    cin>>S;

    int ans=0;
    for(int i=0;i<S.size()/2;i++){
        if(S[i]!=S[S.size()-i-1]){
            ans++;
        }
    }

    cout<<ans<<endl;
}