#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int N;

void dfs(string s,char n){
    if(s.size()==N){
        cout<<s<<endl;
        return;
    }else{
        for(char a='a';a<=n;a++){
            string t=s;
            t+=a;
            dfs(t,max((int)n,a+1));
        }
    }
}

int main(){
    cin>>N;

    dfs("",'a');
}