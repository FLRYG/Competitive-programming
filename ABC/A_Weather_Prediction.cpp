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

    if(S=="Sunny") cout<<"Cloudy"<<endl;
    if(S=="Cloudy") cout<<"Rainy"<<endl;
    if(S=="Rainy") cout<<"Sunny"<<endl;
}