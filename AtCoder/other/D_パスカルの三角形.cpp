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
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;

ll A;

int main(){
    cin>>A;

    cout<<A+1<<' '<<2<<endl;
}

/*
ll N=1000;
ll A;
ll t[2][1000];

int main(){
    cin>>A;

    repn(i,N){
        repn(j,i){
            if(j==1 || j==i){
                t[1][j]=1;
            }else{
                t[1][j]=t[0][j-1]+t[0][j];
            }
        }
        repn(j,i){
            if(t[1][j]==A){
                cout<<i<<' '<<j<<endl;
                return 0;
            }
            if(j==2 && t[1][j]>A){
                cout<<-1<<' '<<-1<<endl;
                return 0;
            }
            t[0][j]=t[1][j];
        }
    }

    cout<<-1<<' '<<endl;
}
*/