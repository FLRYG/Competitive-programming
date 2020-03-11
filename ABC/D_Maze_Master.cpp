#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> P;

const int INF=10000;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int H,W;
char maze[20][20];


int bfs(int sx,int sy){
    int ans[20][20];
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            ans[i][j]=INF;
        }
    }
    ans[sx][sy]=0;

    queue<P> pos;
    pos.push(P(sx,sy));

    while(pos.size()){
        P p=pos.front();
        pos.pop();
        
        for(int i=0;i<4;i++){
            int nx=p.first+dx[i];
            int ny=p.second+dy[i];

            if(0<=nx && nx<H && 0<=ny && ny<W &&
                maze[nx][ny]=='.' && ans[nx][ny]==INF){
                pos.push(P(nx,ny));
                ans[nx][ny]=ans[p.first][p.second]+1;
            }     
        }
    }

    int max=0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(ans[i][j]!=INF && ans[i][j]>max){
                max=ans[i][j];
            }
        }
    }
    
    return max;
}

int main(){
    cin>>H>>W;

    int max=0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>maze[i][j];
        }
    }

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(maze[i][j]=='.'){
                int res=bfs(i,j);
                if(res>max){
                    max=res;
                }
            }
        }
    }
 
    cout<<max;
}