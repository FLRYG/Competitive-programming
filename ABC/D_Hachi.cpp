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
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

string S;

int main(){
    cin>>S;

    if(S.size()<4){
        sort(S.begin(),S.end());
        do{
            int x=0;
            rep(i,S.size()){
                x=x*10+(S[i]-'0');
            }
            //cout<<x<<endl;
            if(x%8==0){
                cout<<"Yes"<<endl;
                return 0;
            }
        }while(next_permutation(S.begin(),S.end()));
        cout<<"No"<<endl;
        return 0;
    }

    vector<int> cnt(10);
    rep(i,S.size()){
        cnt[S[i]-'0']++;
    }

    for(int i=0;i<1000;i+=8){
        vector<int> cntt(10);
        cntt[i%10]++;
        cntt[i/10%10]++;
        cntt[i/100]++;
        if(cntt[0]>0) continue;
        //cout<<i<<endl;
        bool flag=true;
        rep(j,10){
            flag&=cnt[j]>=cntt[j];
        }
        if(flag){
            cout<<"Yes"<<endl;
            return 0;
        }
    }

    cout<<"No"<<endl;
}