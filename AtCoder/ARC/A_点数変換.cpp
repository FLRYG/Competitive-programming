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

int N;
double A,B;
double S[100000];

int main(){
    cin>>N>>A>>B;
    rep(i,N) cin>>S[i];

    bool b=true;
    rep(i,N-1) if(S[i]!=S[i+1]) b=false;
    if(b){
        cout<<-1<<endl;
        return 0;
    }

    double sup=S[1],inf=S[1];
    rep(i,N){
        if(sup<S[i]) sup=S[i];
        if(inf>S[i]) inf=S[i];
    }
    double P=B/(sup-inf);

    double sum=0;
    rep(i,N) sum+=S[i];
    double Q=A-P*sum/N;

    cout<<setprecision(16)<<P<<' '<<Q<<endl;;
}