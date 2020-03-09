//全探索

#include <iostream>
using namespace std;

int n,k;
int a[20];

bool dfs(int i,int sum){
    if (i==n) return sum==k;
    
    //枝分かれ
    if(dfs(i+1,sum)) return true;
    if(dfs(i+1,sum+a[i])) return true;

    return false;
}

int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    if(dfs(0,0)){
        cout<<"Yes";
    }else{
        cout<<"No";
    }

}