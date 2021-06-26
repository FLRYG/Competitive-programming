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
typedef pair<int,int> P;
typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

// 整数の乱数を[a,b]の範囲で返す
struct Random_int{
    int seed, min, max;
    mt19937 mt;
    uniform_int_distribution<int> rand;
    Random_int(int _min, int _max,int _seed=121314): min(_min),max(_max),seed(_seed){
        mt.seed(seed);
        uniform_int_distribution<int>::param_type param(min,max);
        rand.param(param);
    }
    int nextInt(){
        return rand(mt);
    }
};

// 実数の乱数を[a,b]の範囲で返す
struct Random_double{
    int seed, min, max;
    mt19937 mt;
    uniform_real_distribution<double> rand;
    Random_double(int _min, int _max,int _seed=121314): min(_min),max(_max),seed(_seed){
        mt.seed(seed);
        uniform_real_distribution<double>::param_type param(min,max);
        rand.param(param);
    }
    double nextDouble(){
        return rand(mt);
    }
};

// タイマー(秒)
struct Timer{
    long long int starttime;
    Timer(){}
    ~Timer(){}
    private:
    inline long long int nowTime() {
        using namespace std::chrono;
        return duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
    }
    public:
    inline void start(){
        starttime=nowTime();
    }
    inline double getTime(){
        return (nowTime()-starttime)/1e9;
    }
};

const bool LOCALTEST=true;
const double E=2.718281828459045;
const double TIME_LIMIT=2.9;
const double TEMPERATURE0=2e3;
const double TEMPERATURE1=6e2;
Random_double RAND_DOUBLE(0,1);
Timer TIMER;

double temperature=TEMPERATURE0;

inline void updateTemp(double nowTime){
    nowTime/=TIME_LIMIT;
    temperature=pow(TEMPERATURE0,1-nowTime)*pow(TEMPERATURE1,nowTime);
}

template<class S> bool adopt(S delta){
    if(delta>=0) return true;
    else{
        if(RAND_DOUBLE.nextDouble()<=pow(E,delta/temperature)){
            return true;
        }else{
            return false;
        }
    }
}

int N,M;
string S[800];

struct Ginfo{
    int c,d;
    Ginfo(int _c, int _d): c(_c), d(_d) {}
    double computeScore(){
        if(c<M) return round(1e8*double(c)/M);
        else return round(1e8*double(2*N*N)/(2*N*N-d));
    }
    void updateD(vector<vector<char>> &G){
        d=0;
        rep(i,N) rep(j,N) if(G[i][j]=='.') d++;
    }
};

struct Position{
    int a,b,c,d;
    Position(): a(-1), b(-1), c(-1), d(-1) {}
    Position(int _a, int _b, int _c, int _d): a(_a), b(_b), c(_c), d(_d) {}
};

bool overlap(const Position &p, const Position &q){
    if(p.a==-1 || p.a==-1) return false;
    if(p.c<p.a) return overlap(Position(p.a,p.b,N-1,p.d),q)|overlap(Position(0,p.b,p.c,p.d),q);
    else if(p.d<p.b) return overlap(Position(p.a,p.b,p.c,N-1),q)|overlap(Position(p.a,0,p.c,p.d),q);
    else if(q.c<q.a) return overlap(p,Position(q.a,q.b,N-1,q.d))|overlap(p,Position(0,q.b,q.c,q.d));
    else if(q.d<q.b) return overlap(p,Position(q.a,q.b,q.c,N-1))|overlap(p,Position(q.a,0,q.c,q.d));
    return (max(p.a,q.a)<=min(p.c,q.c) && max(p.b,q.b)<=min(p.d,q.d));
}

Position exist(vector<vector<char>> &G, string s){
    int n=s.size();
    Position res;
    rep(i,N) rep(j,N){
        bool flag=true;
        rep(k,n) if(G[i][(j+k)%N]!=s[k]){
            flag=false;
            break;
        }
        if(flag){
            res=Position(i,j,i,(j+n)%N);
            goto exit;
        }
    }
    rep(i,N) rep(j,N){
        bool flag=true;
        rep(k,n) if(G[(i+k)%N][j]!=s[k]){
            flag=false;
            break;
        }
        if(flag){
            res=Position(i,j,(i+n)%N,j);
            goto exit;
        }
    }
    exit:;
    return res;
}

Ginfo solve(vector<vector<char>> &ans){
    Random_int id_rand(0,M-1);
    Random_int G_rand(0,N*N-1);
    Random_int dir_rand(0,1);

    vector<Position> now_S_pos(M);
    Ginfo now_info(0,N*N);

    int loop=0;
    while(TIMER.getTime()<=TIME_LIMIT){
        updateTemp(TIMER.getTime());
        // rep(iii,100){
            if(LOCALTEST) loop++;

            int id=id_rand.nextInt();
            int g=G_rand.nextInt();
            int x=g/N, y=g%N;
            int dir=dir_rand.nextInt();

            Position pos;
            if(dir==0) pos=Position(x,y,x,(y+S[id].size()-1)%N);
            else pos=Position(x,y,(x+S[id].size()-1)%N,y);

            vector<Position> tmp_S_pos=now_S_pos;
            Ginfo tmp_info=now_info;
            vector<vector<char>> G=ans;
            if(dir==0) rep(j,S[id].size()){
                if(G[x][(y+j)%N]=='.') tmp_info.d--;
                G[x][(y+j)%N]=S[id][j];
            }
            else rep(i,S[id].size()){
                if(G[(x+i)%N][y]=='.') tmp_info.d--;
                G[(x+i)%N][y]=S[id][i];
            }

            rep(i,M){
                if(tmp_S_pos[i].a==-1){
                    tmp_S_pos[i]=exist(G,S[i]);
                    if(tmp_S_pos[i].a!=-1) tmp_info.c++;
                }
                else if(overlap(tmp_S_pos[i],pos)){
                    tmp_S_pos[i]=exist(G,S[i]);
                    if(tmp_S_pos[i].a==-1) tmp_info.c--;
                }
            }

            if(adopt(tmp_info.computeScore()-now_info.computeScore())){
                now_S_pos=tmp_S_pos;
                now_info=tmp_info;
                ans=G;
            }
        // }
    }
    if(LOCALTEST) cout<<"loop : "<<loop<<endl;
    return now_info;
}

int main(){
    TIMER.start();
    cin>>N>>M;
    rep(i,M) cin>>S[i];

    vector<vector<char>> ans(N,vector<char>(N,'.'));
    
    Ginfo info=solve(ans);

    rep(i,N){
        rep(j,N) cout<<ans[i][j];
        cout<<endl;
    }

    if(LOCALTEST){
        cout<<info.c<<'/'<<M<<endl;
        cout<<"score : "<<(ll)info.computeScore()<<endl;
    }

    return 0;
}