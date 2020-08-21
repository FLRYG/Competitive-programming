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
//typedef pair<int,int> P;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

string s;

int main(){
    cin>>s;

    int ten=1;
    int Y=0,M=0,D=0;
    rep(i,4){
        Y+=s[i]-'0';
        Y*=10;
    }Y/=10;
    rep(i,2){
        M+=s[i+5]-'0';
        M*=10;
    }M/=10;
    rep(i,2){
        D+=s[i+8]-'0';
        D*=10;
    }D/=10;

    while(Y%(M*D)!=0){
        D++;

        if(M==2){
            bool flag=true;
            if(Y%4==0){
                if(Y%100==0){
                    flag=false;
                    if(Y%400==0) flag=true;
                }else{
                    flag=true;
                }
            }else{
                flag=false;
            }
            if((flag && D>29) || (!flag && D>28)){
                D=1;
                M++;
            }
        }else if(M==4 || M==6 || M==9 || M==11){
            if(D>30){
                D=1;
                M++;
            }
        }else{
            if(D>31){
                D=1;
                M++;
            }
        }

        if(M>12){
            M=1;
            Y++;
        }
    }

    cout<<Y<<'/';
    if(M<10) cout<<0;
    cout<<M<<'/';
    if(D<10) cout<<0;
    cout<<D<<endl;
}