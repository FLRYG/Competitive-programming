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
#include <map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int R;

int main(){
    cin>>R;

    if(R<1200){
        cout<<"ABC"<<endl;
    }else if(R<2800){
        cout<<"ARC"<<endl;
    }else{
        cout<<"AGC"<<endl;
    }
}