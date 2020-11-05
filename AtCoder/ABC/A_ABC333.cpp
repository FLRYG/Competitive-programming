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

int A,B;

int main(){
    cin>>A>>B;

    if(A*B%2==1){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}