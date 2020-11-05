#include <iostream>
#include <string>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int N;
string S;

int main(){
    cin>>N>>S;

    int ans=1;
    char s=S[0];
    for(int i=1;i<N;i++){
        if(s!=S[i]){
            ans++;
        }
        s=S[i];
    }

    cout<<ans;
}