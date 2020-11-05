#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main(){
    string s;
    cin>>s;

    if(regex_match(s,regex("(hi)+"))){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}