#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int n,A,B;

int main(){
    cin>>n;

    if(n==1){
        cout<<"Hello World"<<endl;
    }else{
        cin>>A>>B;
        cout<<A+B<<endl;
    }
}