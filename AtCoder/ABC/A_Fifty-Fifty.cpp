#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

string S;

int main(){
    cin>>S;

    int a=0;
    for(int i=0;i<3;i++){
        for(int j=i+1;j<4;j++){
            if(S[i]==S[j]) a++;
        }
    }

    if(a==2){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}