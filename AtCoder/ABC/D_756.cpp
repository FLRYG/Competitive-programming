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

int N;
int cnt[101];

int main(){
    cin>>N;

    for(int i=2;i<=N;i++){
        int x=i;
        for(int j=2;j<=i;j++){
            if(x%j==0){
                x/=j;
                cnt[j]++;
                j--;
            }
        }
    }

    int c3=0,c5=0,c15=0,c25=0,c75=0;
    repn(i,N){
        if(cnt[i]>=74) c75++;
        else if(cnt[i]>=24) c25++;
        else if(cnt[i]>=14) c15++;
        else if(cnt[i]>=4) c5++;
        else if(cnt[i]>=2) c3++;
    }

    int ans=0;
    ans+=(c5+c15+c25+c75)*(c5+c15+c25+c75-1)/2*(c3+c5+c15+c25+c75-2);
    ans+=(c25+c75)*(c3+c5+c15+c25+c75-1);
    ans+=(c15+c25+c75)*(c5+c15+c25+c75-1);
    ans+=c75;

    cout<<ans<<endl;
}