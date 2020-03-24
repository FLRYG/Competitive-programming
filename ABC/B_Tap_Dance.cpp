#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

string S;

int main(){
    cin>>S;

    for(int i=0;i<S.size();i++){
        if((i%2==0 && S[i]=='L') ||
            i%2==1 && S[i]=='R'){
            cout<<"No"<<endl;
            return 0;
        }
    }

    cout<<"Yes"<<endl;
}