#include <iostream>
#include <map>
using namespace std;

int main(){
    int N;
    map<int,int> m;
    cin>>N;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        m[a]++;
    }

    for(const auto& x:m){
        if(x.second>=2){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}