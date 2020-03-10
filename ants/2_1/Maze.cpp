//全探索
//幅優先探索

#include <iostream>
#include <queue>
using namespace std;

typedef pair<int,int> P;

const int INF=100100;

int N,M;
char maze[105][105]={};
int sx,sy;
int gx,gy;

int d[105][105];

//         r,u,l,d
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

//探索
int bfs(){
    queue<P> que;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            d[i][j]=INF;
        }
    }
    que.push(P(sx,sy));
    d[sx][sy]=0;

    while(que.size()){
        P p=que.front();
        que.pop();

        if(p.first==gx && p.second==gy) break;

        for(int i=0;i<4;i++){
            int nx=p.first+dx[i];
            int ny=p.second+dy[i];

            if(1<=nx && nx<=N && 1<=ny && ny<=M &&
                maze[nx][ny]!='#' && d[nx][ny]==INF){
                que.push(P(nx,ny));
                d[nx][ny]=d[p.first][p.second]+1;
            }
        }
    }

    return d[gx][gy];
}

int main(){
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>maze[i][j];
            if(maze[i][j]=='s'){
                sx=i,sy=j;
            }else if(maze[i][j]=='g'){
                gx=i,gy=j;
            }
        }
    }

    cout<<bfs();
}