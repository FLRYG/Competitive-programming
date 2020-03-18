#include <iostream>
#include <string>
using namespace std;

string S;
string X[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};

int main(){
    cin>>S;
    int ans;
    for(int i=0;i<7;i++){
        if(X[i]==S){
            ans=7-i;
            break;
        }
    }

    cout<<ans<<endl;
}