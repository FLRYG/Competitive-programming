#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> P;

const int INF=10000;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int H,W;
char maze[20][20];
int sx,sy;
queue<P> pos;

int ans[20][20];

int main(){
    cin>>H>>W;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>maze[i][j];
            if(maze[i][j]=='.'){
                sx=i,sy=j;
            }
        }
    }

    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            ans[i][j]=INF;
        }
    }
    ans[sx][sy]=0;
    pos.push(P(sx,sy));

    while(pos.size()){
        for(int i=0;i<4;i++){
            pos.front
            if()
        }
    }
}