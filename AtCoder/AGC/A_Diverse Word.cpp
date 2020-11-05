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

string S;
int a[26];
int b[26];

int main(){
    cin>>S;
    if(S=="zyxwvutsrqponmlkjihgfedcba"){
        cout<<-1<<endl;
        return 0;
    }

    string ans="";
    if(S.size()!=26){
        rep(i,S.size()) a[S[i]-'a']++;
        rep(i,26){
            if(a[i]==0){
                ans=S+(char)('a'+i);
                break;
            }
        }
    }else{
        rep(i,S.size()){
            a[i]=S[i]-'a';
            b[i]=S[i]-'a';
        }
        next_permutation(b,b+26);
        bool flag=true;
        rep(i,S.size()){
            if(flag){
                char c=b[i]+'a';
                ans+=c;
                if(a[i]!=b[i]){
                    flag=false;
                }
            }
        }
    }

    cout<<ans<<endl;
}