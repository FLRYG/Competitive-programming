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

map<string,int> m;
int memo[99999];
int N;
string s;

void dfs(int start,int end){
    int v1,v2,vc;
    int c=(start+end)/2;

    if(memo[start]==-1){
        cout<<start<<'\n'<<flush;
        cin>>s;
        if(m[s]==2){
            cout<<start<<'\n'<<flush;
            return;
        }
        v1=memo[start]=m[s];
    }else{
        v1=memo[start];
    }
    
    if(memo[end]==-1){
        cout<<end<<'\n'<<flush;
        cin>>s;
        if(m[s]==2){
            cout<<end<<'\n'<<flush;
            return;
        }
        v2=memo[end]=m[s];
    }else{
        v2=memo[end];
    }

    if(memo[start]!=memo[end] && end-start<=2){
        cout<<start+1<<'\n'<<flush;
        return;
    }

    if(memo[c]==-1){
        cout<<c<<'\n'<<flush;
        cin>>s;
        if(m[s]==2){
            cout<<end<<'\n'<<flush;
            return;
        }
        vc=memo[c]=m[s];
    }else{
        vc=memo[c];
    }

    if(v1!=vc){
        dfs(start,c);
    }else if(v2!=vc){
        dfs(c,end);
    }
}

int main(){
    m["Male"]=0;
    m["Female"]=1;
    m["Vacant"]=2;
    fill(memo,memo+N,-1);
    cin>>N;

    dfs(0,N-1);
}