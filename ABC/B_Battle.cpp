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

int A,B,C,D;

int main(){
    cin>>A>>B>>C>>D;

    int i=1;
    while(true){
        if(i&1){
            C-=B;
        }else{
            A-=D;
        }
        if(A<=0){
            cout<<"No"<<endl;
            return 0;
        }
        if(C<=0){
            cout<<"Yes"<<endl;
            return 0;
        }
        i++;
    }
}