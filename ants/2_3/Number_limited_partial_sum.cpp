#include <iostream>
#include <algorithm>
using namespace std;

int N,K;
int a[100],m[100];

//O(K Σ_(i)(m_i)) で不十分
bool dp1[100+1][100000+1];
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

//O(NK) で十分
int dp2[100000+1];
void solve(){
    fill(dp2,dp2+100001,-1);
    dp2[0]=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<=K;j++){
            if(dp2[j]>=0){
                dp2[j]=m[i];
            }else if(j<a[i] || dp2[j-a[i]]<=0){
                dp2[j]=-1;
            }else{
                dp2[j]=dp2[j-a[i]]-1;
            }
        }
    }

    if(dp2[K]>=0){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
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