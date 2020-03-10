//全探索
//深さ優先探索

#include <iostream>
using namespace std;

int N,M;
char field[105][105]={};

void dfs(int i,int j){
    field[i][j]='.';

    for(int k=-1;k<=1;k++){
        for(int l=-1;l<=1;l++){
            if(field[i+k][j+l]=='w'){
                dfs(i+k,j+l);
            }
        }
    }
}

int main(){
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>field[i][j];
        }
    }

    int count=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(field[i][j]=='w'){
                dfs(i,j);
                count++;
            }
        }
    }

    cout<<count;
}