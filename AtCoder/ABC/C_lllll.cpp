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

int n;
int veven[100000];
int vodd[100000];

int main(){
    cin>>n;
    rep(i,n){
        int v;
        cin>>v;
        if(i%2==0) veven[v]++;
        else vodd[v]++;
    }

    pair<int,int> evenmax(0,0), evenmax2(-1,-1);
    pair<int,int>  oddmax(0,0),  oddmax2(-1,-1);
    rep(i,100000){
        if(veven[i]>evenmax.second){
            evenmax2=evenmax;
            evenmax=pair<int,int>(i,veven[i]);
        }else if(veven[i]>evenmax2.second){
            evenmax2=pair<int,int>(i,veven[i]);
        }
    }
    rep(i,100000){
        if(vodd[i]>oddmax.second){
            oddmax2=oddmax;
            oddmax=pair<int,int>(i,vodd[i]);
        }else if(vodd[i]>oddmax2.second){
            oddmax2=pair<int,int>(i,vodd[i]);
        }
    }

    int ans;
    if(evenmax.first!=oddmax.first){
        ans=n-evenmax.second-oddmax.second;
    }else{
        ans=min(n-evenmax.second-oddmax2.second,n-oddmax.second-evenmax2.second);
    }

    cout<<ans<<endl;
}