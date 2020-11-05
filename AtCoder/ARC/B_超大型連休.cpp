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

const int month[]={0,0,31,60,91,121,152,182,213,244,274,305,335,366};

int N;
int m[366];
int d[366];
int day[367];

int main(){
    cin>>N;
    rep(i,N){
        string s;
        cin>>s;
        int x;
        rep(j,s.size()){
            if(s[j]=='/') x=j;
        }
        string M,D;
        rep(j,x) M+=s[j];
        for(int j=x+1;j<s.size();j++) D+=s[j];

        m[i]=atoi(M.c_str()); 
        d[i]=atoi(D.c_str()); 
    }

    repn(i,366){
        if(i%7==1 || i%7==0) day[i]=1;
    }

    rep(i,N){
        int x=month[m[i]]+d[i];        
        while(x<=366 && day[x]) x++;
        if(x<=366) day[x]=1;
    }

    int ans=0;
    int sum=0;
    repn(i,366){
        if(day[i]==1) sum++;
        else{
            ans=max(ans,sum);
            sum=0;
        }
    }
    ans=max(ans,sum);

    cout<<ans<<endl;
}