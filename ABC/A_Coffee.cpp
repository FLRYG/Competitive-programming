#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

string S;

int main(){
    cin>>S;

    if(S[2]==S[3] && S[4]==S[5]){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}