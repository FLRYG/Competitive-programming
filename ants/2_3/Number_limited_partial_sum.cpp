#include <iostream>
#include
using namespace std;

int N,K;
int a[100],m[100];

//O(K Σ_(i)(K_i)) で不十分
bool dp1[100+1][100+1];
void solve1(){
    dp1[0][0]=true;
    for(int i=0;i<N;i++){
        for(int j=0;j<=K;j++){
            for(int k=0;k<=m[i]&&k*a[i]<=j;k++){
                dp1[i+1][j]|=dp1[i][j-k*a[i]];
            }
        }
    }

    if(dp1[N][K]){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}

int dp2[100+1][100+1];
void solve(){
    fill(dp2,dp2+N,-1);
    
}

int main(){
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
    for(int i=0;i<N;i++){
        cin>>m[i];
    }

    
}