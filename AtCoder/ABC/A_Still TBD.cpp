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

    if(S[5]=='0' && 
      (S[6]=='1' || S[6]=='2' || S[6]=='3' || S[6]=='4')){
          cout<<"Heisei"<<endl;
    }else{
        cout<<"TBD"<<endl;
    }
}