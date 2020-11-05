#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int X;
vector<int> p={2};

int main(){
    cin>>X;

    if(X==2){
        cout<<2;
        return 0;
    }

    bool b=true;
    int n=2;
    while(b){
        n++;
        bool prime;
        for(int i=0;i<p.size();i++){
            if(n%p[i]==0){
                prime=false;
                break;
            }else{
                prime=true;
            }
        }
        if(prime){
            p.push_back(n);
            if(n>=X){
                b=false;
            }
        }
    }

    cout<<n;
}