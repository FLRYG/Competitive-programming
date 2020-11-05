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

string b;

int main(){
    cin>>b;

    rep(i,b.size()){
        if(b[i]=='A') b[i]='T';
        else if(b[i]=='T') b[i]='A';
        else if(b[i]=='G') b[i]='C';
        else if(b[i]=='C') b[i]='G';
    }

    cout<<b<<endl;
}