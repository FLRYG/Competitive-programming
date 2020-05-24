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
typedef pair<int,int> P;

int H,W;
char A[100][100];
int cnt[26];

int main(){
    cin>>H>>W;
    rep(i,H) rep(j,W){
        cin>>A[i][j];
        cnt[A[i][j]-'a']++;
    }

    bool res=true;
    if(H%2==0 && W%2==0){
        rep(i,26){
            if(cnt[i]%4!=0){
                res=false;
                break;
            }
        }
    }else if(H%2==1 && W%2==1){
        int c1=0, c2=0;
        rep(i,26){
            if(cnt[i]&1){
                c1++;
                cnt[i]--;
            }
            if(cnt[i]%2==0 && cnt[i]%4!=0) c2++;
        }
        if(!(c1==1 && c2<=H/2+W/2)){
            res=false;
        }
    }else{
        int odd=H&1?H:W;
        int even=H+W-odd;
        int c1=0, c2=0;
        rep(i,26){
            if(cnt[i]&1){
                c1++;
                cnt[i]--;
            }
            if(cnt[i]%2==0 && cnt[i]%4!=0) c2++;
        }
        if(!(c1==0 && c2<=even/2)){
            res=false;
        }
    }
    if(res){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}