#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

void reverse(string &s){
    char tmp;
    for(int i=0;i<s.size()/2;i++){
        tmp=s.at(i);
        s.at(i)=s.at(s.size()-1-i);
        s.at(s.size()-1-i)=tmp;
    }
}

int main(){
    string S;
    int Q;
    cin>>S;
    cin>>Q;
    vector<char> v;

    int T;
    int F;
    char C;
    for(int i=0;i<Q;i++){
        cin>>T;
        if(T==1){
            reverse(S);
        }else{
            cin>>F>>C;
            if(F==1){
                S.insert(S.begin(),C);
            }else{
                S.push_back(C);
            }
        }
    }

    cout<<S;
}