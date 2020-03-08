#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//二つのstringに分けて考える
int main(){
    string S;
    cin>>S;
    int Q;
    cin>>Q;
    string R;

    int t,f;
    char c;
    bool b=false;
    for(int i=0;i<Q;i++){
        cin>>t;
        if(t==1){
            string tmp=S;
            S=R;
            R=tmp;
        }else{
            cin>>f>>c;
            if(f==1){
                R+=c;
            }else{
                S+=c;
            }
        }
    }
    reverse(R.begin(),R.end());
    string ans=R+S;

    cout<<ans;
}

/*
TLE :reverse,insertに時間がかかる

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
*/