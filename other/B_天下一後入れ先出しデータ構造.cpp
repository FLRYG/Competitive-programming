#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>
#include <regex>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
//int const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

ll Q,L;
string query[100000];
stack<P> sta;

int main(){
    cin>>Q>>L;
    cin.ignore();
    rep(i,Q) getline(cin,query[i]);

    smatch sma;
    ll sum=0;
    rep(i,Q){
        string s=query[i];
        if(regex_search(s,sma,regex("Push"))){
            ll N=0, M=0;
            ll ten=1, idx=s.size()-1;
            do{
                M+=(s[idx]-'0')*ten;
                ten*=10;
            }while(s[--idx]!=' ');
            idx--;
            ten=1;
            do{
                N+=(s[idx]-'0')*ten;
                ten*=10;
            }while(s[--idx]!=' ');

            sta.push(P(M,N));
            sum+=N;
            if(sum>L){
                cout<<"FULL"<<endl;
                return 0;
            }
        }else if(regex_search(s,sma,regex("Pop"))){
            ll N=0;
            ll ten=1, idx=s.size()-1;
            do{
                N+=(s[idx]-'0')*ten;
                ten*=10;
            }while(s[--idx]!=' ');
            if(N>sum){
                cout<<"EMPTY"<<endl;
                return 0;
            }
            sum-=N;
            while(N>0){
                P p=sta.top(); sta.pop();
                if(p.second>N){
                    sta.push(P(p.first,p.second-N));
                    N-=N;
                }else{
                    N-=p.second;
                }
            }
        }else if(regex_search(s,sma,regex("Top"))){
            if(sta.empty()){
                cout<<"EMPTY"<<endl;
                return 0;
            }
            cout<<sta.top().first<<endl;
        }else if(regex_search(s,sma,regex("Size"))){
            cout<<sum<<endl;
        }
    }
    cout<<"SAFE"<<endl;
}