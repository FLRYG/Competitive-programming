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

int N;
string W[100];

int main(){
    cin>>N;
    rep(i,N) cin>>W[i];

    repn(i,N-1){
        if(W[i][0]==W[i-1][W[i-1].size()-1]){
            rep(j,i){
                if(W[i]==W[j]){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }else{
            cout<<"No"<<endl;
            return 0;
        }
    }

    cout<<"Yes"<<endl;
}