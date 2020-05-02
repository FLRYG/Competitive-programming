#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int K,A,B;

int main(){
    cin>>K>>A>>B;

    for(int i=A;i<=B;i++){
        if(i%K==0){
            cout<<"OK";
            return 0;
        }
    }

    cout<<"NG"<<endl;
}