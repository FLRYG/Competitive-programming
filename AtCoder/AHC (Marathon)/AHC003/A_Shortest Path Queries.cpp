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

// タイマー(ミリ秒)
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
struct Random_int{
    int seed, min, max;
    mt19937 mt;
    uniform_int_distribution<int> rand;
    Random_int(int _min, int _max, int _seed=121314): min(_min),max(_max),seed(_seed){
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
    Random_double(int _min, int _max, int _seed=121314): min(_min),max(_max),seed(_seed){
        mt.seed(seed);
        uniform_real_distribution<double>::param_type param(min,max);
        rand.param(param);
    }
    double nextDouble(){
        return rand(mt);
    }
};

mt19937 engine(121314);
Random_int rand_01(0,1);
int const I[]={1,0,-1,0};
int const J[]={0,1,0,-1};

struct Grid{
    int h[30][29];
    int v[29][30];
    int si[1000], sj[1000];
    int ti[1000], tj[1000];
    double a[1000];
    double e[1000];
    int result[1000];
    double score=0.0;

    void read_h_v(){
        rep(i,30) rep(j,29) cin>>h[i][j];
        rep(i,29) rep(j,30) cin>>v[i][j];
    }
    void read_s_t_a_e(int k){
        cin>>si[k]>>sj[k]>>ti[k]>>tj[k]>>a[k]>>e[k];
    }
    void read_s_t(int k){
        cin>>si[k]>>sj[k]>>ti[k]>>tj[k];
    }
    void read_result(int k){
        cin>>result[k];
    }

    int compute_path_length(int i, int j, string path){
        int res=0;
        for(char &c:path){
            if(c=='D') res+=v[i++][j];
            else if(c=='U') res+=v[--i][j];
            else if(c=='R') res+=h[i][j++];
            else if(c=='L') res+=h[i][--j];
        }
        return res;
    }
    void compute_result(int k, string path){
        int b=compute_path_length(si[k],sj[k],path);
        score=score*0.998+a[k]/b;
        result[k]=round(b*e[k]);
    }

    int est_dist_h[30][29];
    int est_dist_v[29][30];
    int cnt_h[30][29];
    int cnt_v[29][30];
    double sum_est_dist_h[30][29];
    double sum_est_dist_v[29][30];
    double prob[1000];
    int est_result[1000];

    Grid(){
        for(auto e:est_dist_h) fill(e,e+29,5000);
        for(auto e:est_dist_v) fill(e,e+30,5000);
        prob[0]=1;
        rep(i,999) prob[i+1]=prob[i]*0.998;
    }

    int compute_est_path_length(int i, int j, string path){
        int res=0;
        for(char &c:path){
            if(c=='D') res+=v[i++][j];
            else if(c=='U') res+=v[--i][j];
            else if(c=='R') res+=h[i][j++];
            else if(c=='L') res+=h[i][--j];
        }
        return res;
    }

    string compute_random_path(int k){
        string path;
        int d[2]={ti[k]-si[k],tj[k]-sj[k]};
        char c[2];
        c[0]=d[0]>0?'D':'U';
        c[1]=d[1]>0?'R':'L';
        d[0]=abs(d[0]), d[1]=abs(d[1]);
        // path=string(d[0],c[0])+string(d[1],c[1]);
        // shuffle(path.begin(),path.end(),engine);
        // est_result[k]=compute_est_path_length(si[k],sj[k],path);
        if(rand_01.nextInt()) path=string(d[0],c[0])+string(d[1],c[1]);
        else path=string(d[1],c[1])+string(d[0],c[0]);
        return path;
    }

    string compute_est_short_path(int k){
        // cout<<"  "<<si[k]<<' '<<sj[k]<<' '<<ti[k]<<' '<<tj[k]<<endl;
        vector<vector<int>> cost(30,vector<int>(30,700000));
        vector<vector<P>> prev(30,vector<P>(30));
        prev[si[k]][sj[k]]={-1,-1};
        priority_queue<IP,vector<IP>,greater<IP>> que;
        que.push({0,{si[k],sj[k]}});
        while(!que.empty()){
            IP ip=que.top(); que.pop();
            int v=ip.first;
            int i=ip.second.first;
            int j=ip.second.second;
            if(v>=cost[i][j]) continue;
            cost[i][j]=v;
            // if(k==191) cout<<i<<' '<<j<<' '<<v<<endl;
            if(i==ti[k] && j==tj[k]) break;
            if(i+1<30) que.push({v+est_dist_v[i][j],{i+1,j}});
            if(0<=i-1) que.push({v+est_dist_v[i-1][j],{i-1,j}});
            if(j+1<30) que.push({v+est_dist_h[i][j],{i,j+1}});
            if(0<=j-1) que.push({v+est_dist_h[i][j-1],{i,j-1}});
        }
        est_result[k]=cost[ti[k]][tj[k]];
        // if(k==139){
        //     cout<<" "<<'\t';
        //     rep(i,30) cout<<i<<'\t'; cout<<endl;
        //     rep(i,30){
        //         cout<<i<<'\t';
        //         rep(j,30){
        //             cout<<cost[i][j]<<'\t'; 
        //         }
        //         cout<<endl;
        //     }
        //     cout<<est_dist_v[18][12]<<endl;
        // }
        string path;
        int i=ti[k], j=tj[k];
        while(i!=si[k] || j!=sj[k]){
            // if(k==139) cout<<i<<' '<<j<<endl;
            if(i+1<30 && cost[i][j]==cost[i+1][j]+est_dist_v[i][j]) path+='U', i++;
            else if(0<=i-1 && cost[i][j]==cost[i-1][j]+est_dist_v[i-1][j]) path+='D', i--;
            else if(j+1<30 && cost[i][j]==cost[i][j+1]+est_dist_h[i][j]) path+='L', j++;
            else if(0<=j-1 && cost[i][j]==cost[i][j-1]+est_dist_h[i][j-1]) path+='R', j--;
        }
        reverse(path.begin(),path.end());
        return path;
    }

    void update_est_dist(int k, string path){
        int i=si[k], j=sj[k];
        double ave_dist=(double)result[k]/path.size();
        for(char &c:path){
            if(c=='D') sum_est_dist_v[i][j]+=ave_dist, cnt_v[i++][j]++;
            else if(c=='U') sum_est_dist_v[--i][j]+=ave_dist, cnt_v[i][j]++;
            else if(c=='R') sum_est_dist_h[i][j]+=ave_dist, cnt_h[i][j++]++;
            else if(c=='L') sum_est_dist_h[i][--j]+=ave_dist, cnt_h[i][j]++;
        }
        rep(i,30) rep(j,29) if(cnt_h[i][j]) est_dist_h[i][j]=min(1000,(int)round(sum_est_dist_h[i][j]/cnt_h[i][j]));
        rep(i,29) rep(j,30) if(cnt_v[i][j]) est_dist_v[i][j]=min(1000,(int)round(sum_est_dist_v[i][j]/cnt_v[i][j]));
        // for(char &c:path){
        //     if(c=='D') sum_est_dist_v[i][j]=ave_dist, cnt_v[i++][j]++;
        //     else if(c=='U') sum_est_dist_v[--i][j]=ave_dist, cnt_v[i][j]++;
        //     else if(c=='R') sum_est_dist_h[i][j]=ave_dist, cnt_h[i][j++]++;
        //     else if(c=='L') sum_est_dist_h[i][--j]=ave_dist, cnt_h[i][j]++;
        // }
    }
};

Random_double rand_dou(0,1);
string query(int k, Grid &G) {
    string path;
    if(rand_dou.nextDouble()<=G.prob[k]){
        // cout<<k<<' '<<0<<':'<<endl;
        // ランダムに構成
        path=G.compute_random_path(k);
    }else{
        // cout<<k<<' '<<1<<':'<<endl;
        // 推定最短パスを構成
        path=G.compute_est_short_path(k);
    }
    return path;
}

const bool LOCAL_TEST=true;

int main() {
    Grid G;
    if(LOCAL_TEST){
        G.read_h_v();
    }
    rep(k,1000){
        if(LOCAL_TEST){
            G.read_s_t_a_e(k);
        }else{
            G.read_s_t(k);
        }
        string path=query(k,G);
        cout<<path<<endl<<flush;
        if(LOCAL_TEST){
            G.compute_result(k,path);
        }else{
            G.read_result(k);
        }
        G.update_est_dist(k,path);
    }
    if (LOCAL_TEST) {
        cout<<setprecision(16)<<round(2312311*G.score)<<endl;
    }
    return 0;
}