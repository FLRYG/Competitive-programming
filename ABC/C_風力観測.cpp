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
//typedef pair<ll,ll> P;
//ll const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

double Deg;
double Dis;

int main(){
    cin>>Deg>>Dis;

    Deg*=10;
    string Dir;
    if(1125<=Deg && Deg<3375) Dir="NNE";
    else if(3375<=Deg && Deg<5625) Dir="NE";
    else if(5625<=Deg && Deg<7875) Dir="ENE";
    else if(7875<=Deg && Deg<10125) Dir="E";
    else if(10125<=Deg && Deg<12375) Dir="ESE";
    else if(12375<=Deg && Deg<14625) Dir="SE";
    else if(14625<=Deg && Deg<16875) Dir="SSE";
    else if(16875<=Deg && Deg<19125) Dir="S";
    else if(19125<=Deg && Deg<21375) Dir="SSW";
    else if(21375<=Deg && Deg<23625) Dir="SW";
    else if(23625<=Deg && Deg<25875) Dir="WSW";
    else if(25875<=Deg && Deg<28125) Dir="W";
    else if(28125<=Deg && Deg<30375) Dir="WNW";
    else if(30375<=Deg && Deg<32625) Dir="NW";
    else if(32625<=Deg && Deg<34875) Dir="NNW";
    else Dir="N";

    Dis=round(Dis/60*10)/10;
    int W;
    if(32.7<=Dis) W=12;
    else if(28.5<=Dis) W=11;
    else if(24.5<=Dis) W=10;
    else if(20.8<=Dis) W=9;
    else if(17.2<=Dis) W=8;
    else if(13.9<=Dis) W=7;
    else if(10.8<=Dis) W=6;
    else if(8.0<=Dis) W=5;
    else if(5.5<=Dis) W=4;
    else if(3.4<=Dis) W=3;
    else if(1.6<=Dis) W=2;
    else if(0.3<=Dis) W=1;
    else if(0.0<=Dis) W=0;

    if(W==0) Dir="C";

    cout<<Dir<<' '<<W<<endl;
}