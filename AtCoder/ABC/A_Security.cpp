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

    rep(i,3){
        if(S[i]==S[i+1]){
            cout<<"Bad"<<endl;
            return 0;
        }
    }

    cout<<"Good"<<endl;
}