#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <chrono>
#include <random>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
// typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

struct Timer{
    double starttime;
    Timer(){}
    ~Timer(){}
    inline double nowTime() {
        using namespace std::chrono;
        return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    }
    inline void start(){
        starttime=nowTime();
    }
    inline double getTime(){
        return nowTime()-starttime;
    }
};

// 整数の乱数を[a,b]の範囲で返す
struct Random{
    int seed, min, max;
    mt19937 mt;
    uniform_int_distribution<int> rand;
    Random(int _min, int _max, int _seed=121314): min(_min),max(_max),seed(_seed){
        mt.seed(seed);
        uniform_int_distribution<int>::param_type param(min,max);
        rand.param(param);
    }
    ~Random(){}
    int nextInt(){
        return rand(mt);
    }
};

int I[]={1,0,-1,0};
int J[]={0,1,0,-1};

int N=50;
int si, sj;
int t[50][50];
int p[50][50];
Timer timer;

string solve1(){
    string ans="";
    int score=0;
    vector<int> chk(N*N,1);
    vector<vector<int>> chkg(N,vector<int>(N,0));
    int x=si, y=sj;
    string tmpans="";
    int tmpscore=0;
    Random r(1,1000);
    // int cnt=0;
    while(timer.getTime()<1970){
        rep(roop,500){
            if(r.nextInt()<=5){
                repr(e,chk) e=1;
                int i=si, j=sj;
                chk[t[i][j]]=0;
                rep(k,tmpans.size()){
                    if(tmpans[k]=='D') i+=I[0], j+=J[0];
                    else if(tmpans[k]=='R') i+=I[1], j+=J[1];
                    else if(tmpans[k]=='U') i+=I[2], j+=J[2];
                    else if(tmpans[k]=='L') i+=I[3], j+=J[3];
                    chk[t[i][j]]=0;
                }
            }
            while(true){
                if(!chkg[x][y]) tmpscore+=p[x][y];
                chkg[x][y]=1;
                chk[t[x][y]]=0;
                int maxi=-1;
                int id=-1;
                rep(k,4){
                    int i=x+I[k];
                    int j=y+J[k];
                    if(0<=i && i<N && 0<=j && j<N && chk[t[i][j]] && maxi<p[i][j]){
                        // cout<<p[i][j]<<endl;
                        maxi=p[i][j];
                        id=k;
                    }
                }
                if(id==-1) break;
                // cout<<id<<endl;
                x+=I[id];
                y+=J[id];
                if(id==0) tmpans+='D'; 
                else if(id==1) tmpans+='R'; 
                else if(id==2) tmpans+='U'; 
                else if(id==3) tmpans+='L'; 
            }
            // cnt++;
            if(tmpscore>score){
                score=tmpscore;
                ans=tmpans;
            }
            if(tmpans.size()==0) continue;
            tmpscore-=p[x][y];
            chkg[x][y]=0;
            if(tmpans[tmpans.size()-1]=='D') x-=I[0], y-=J[0];
            else if(tmpans[tmpans.size()-1]=='R') x-=I[1], y-=J[1];
            else if(tmpans[tmpans.size()-1]=='U') x-=I[2], y-=J[2];
            else if(tmpans[tmpans.size()-1]=='L') x-=I[3], y-=J[3];
            tmpans.pop_back();
        }
    }
    // cout<<score<<endl;
    // cout<<cnt<<endl;

    return ans;
}

string solve2(){
    string ans="";
    int score=0;
    vector<int> chk(N*N,1);
    vector<vector<int>> chkg(N,vector<int>(N,0));
    int x=si, y=sj;
    string tmpans="";
    int tmpscore=0;
    Random rand(1,1000);
    // int cnt=0;
    while(timer.getTime()<1970){
        rep(roop,500){
            if(rand.nextInt()<=5){
                repr(e,chk) e=1;
                int i=si, j=sj;
                chk[t[i][j]]=0;
                rep(k,tmpans.size()){
                    if(tmpans[k]=='D') i+=I[0], j+=J[0];
                    else if(tmpans[k]=='R') i+=I[1], j+=J[1];
                    else if(tmpans[k]=='U') i+=I[2], j+=J[2];
                    else if(tmpans[k]=='L') i+=I[3], j+=J[3];
                    chk[t[i][j]]=0;
                }
            }
            while(true){
                if(!chkg[x][y]) tmpscore+=p[x][y];
                chkg[x][y]=1;
                chk[t[x][y]]=0;
                int maxi=-1;
                int id=-1;
                int next=rand.nextInt();
                if(next<=600){
                    rep(k,4){
                        int i=x+I[k];
                        int j=y+J[k];
                        if(0<=i && i<N && 0<=j && j<N && chk[t[i][j]] && maxi<p[i][j]){
                            // cout<<p[i][j]<<endl;
                            maxi=p[i][j];
                            id=k;
                        }
                    }
                }else{
                    int m=next%4;
                    int i=x+I[m];
                    int j=y+J[m];
                    if(0<=i && i<N && 0<=j && j<N && chk[t[i][j]]) id=m;
                    else{
                        rep(k,4){
                            int i=x+I[k];
                            int j=y+J[k];
                            if(0<=i && i<N && 0<=j && j<N && chk[t[i][j]] && maxi<p[i][j]){
                                // cout<<p[i][j]<<endl;
                                maxi=p[i][j];
                                id=k;
                            }
                        }
                    }
                }
                if(id==-1) break;
                // cout<<id<<endl;
                x+=I[id];
                y+=J[id];
                if(id==0) tmpans+='D'; 
                else if(id==1) tmpans+='R'; 
                else if(id==2) tmpans+='U'; 
                else if(id==3) tmpans+='L'; 
            }
            // cnt++;
            if(tmpscore>score){
                score=tmpscore;
                ans=tmpans;
            }
            if(tmpans.size()==0) continue;
            tmpscore-=p[x][y];
            chkg[x][y]=0;
            if(tmpans[tmpans.size()-1]=='D') x-=I[0], y-=J[0];
            else if(tmpans[tmpans.size()-1]=='R') x-=I[1], y-=J[1];
            else if(tmpans[tmpans.size()-1]=='U') x-=I[2], y-=J[2];
            else if(tmpans[tmpans.size()-1]=='L') x-=I[3], y-=J[3];
            tmpans.pop_back();
        }
    }
    // cout<<score<<endl;
    // cout<<cnt<<endl;

    return ans;
}

int main(){
    cin>>si>>sj;
    rep(i,N) rep(j,N) cin>>t[i][j];
    rep(i,N) rep(j,N) cin>>p[i][j];
    timer.start();

    string ans=solve2();

    cout<<ans<<endl;
    
    return 0;
}