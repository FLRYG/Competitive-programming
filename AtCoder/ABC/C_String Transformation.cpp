#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

string S,T;
int memo[26];

int main(){
    cin>>S>>T;

    rep(i,26) memo[i]=-1;
    rep(i,S.size()){
        if(memo[S[i]-'a']==-1){
            //cout<<"memo["<<S[i]-'a'<<"] = "<<T[i]<<endl;
            memo[S[i]-'a']=T[i];
        }else{
            if(memo[S[i]-'a']!=T[i]){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }

    rep(i,26) memo[i]=-1;
    rep(i,T.size()){
        if(memo[T[i]-'a']==-1){
            //cout<<"memo["<<T[i]-'a'<<"] = "<<S[i]<<endl;
            memo[T[i]-'a']=S[i];
        }else{
            if(memo[T[i]-'a']!=S[i]){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }

    cout<<"Yes"<<endl;
}