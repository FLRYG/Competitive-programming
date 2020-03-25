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

string S,T;

int main(){
    cin>>S>>T;
    
    int ans=0;
    for(int i=0;i<3;i++){
        if(S[i]==T[i]) ans++;
    }

    cout<<ans<<endl;
}