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
ll const MOD=1'000'000'007;

int N;
string S;
queue<string> ans;

void print(string qx, int idx){
    string T=S;
    T.insert(idx,"q");
    string res;
    res+=qx;
    res+=": ";
    res+=T;
    ans.push(res);
}

int q0(int idx);
int q1(int idx);
int q2(int idx);
int q3(int idx);
int qacc(int idx);

int main(){
    cin>>S;
    N=S.size();
    int cnt=q0(0);
    int i=1;
    while(!ans.empty()){
        cout<<i++<<": "<<ans.front()<<endl;
        ans.pop();
    }
    cout<<"result: "<<S<<", count: "<<cnt<<endl;
}

int q0(int idx){
    int cnt=0;
    print("q0",idx);
    if(idx==N){
        cnt+=qacc(idx-1);
    }else if(S[idx]=='0'){
        S[idx]='x';
        cnt+=q1(idx+1);
    }else if(S[idx]=='1'){
        cnt+=q0(idx+1);
    }
    return cnt+1;
}

int q1(int idx){
    int cnt=0;
    print("q1",idx);
    if(idx==N){
        cnt+=q3(idx-1);
    }else if(S[idx]=='0'){
        cnt+=q1(idx+1);
    }else if(S[idx]=='1'){
        S[idx]='0';
        cnt+=q2(idx-1);
    }
    return cnt+1;
}

int q2(int idx){
    int cnt=0;
    print("q2",idx);
    if(S[idx]=='0'){
        cnt+=q2(idx-1);
    }else if(S[idx]=='x'){
        S[idx]='1';
        cnt+=q0(idx+1);
    }
    return cnt+1;
}

int q3(int idx){
    int cnt=0;
    print("q3",idx);
    if(S[idx]=='0'){
        cnt+=q3(idx-1);
    }else if(S[idx]=='x'){
        S[idx]='0';
        cnt+=qacc(idx+1);
    }
    return cnt+1;
}

int qacc(int idx){
    print("qacc",idx);
    return 1;
}