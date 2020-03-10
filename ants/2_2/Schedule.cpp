//貪欲法

#include <iostream>
#include <algorithm>
using namespace std;

int N;

pair<int,int> itv[100100];

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>itv[i].second;
        cin>>itv[i].first;
    }

    sort(itv,itv+N);

    int ans=0;
    int fin=-1;
    for(int i=0;i<N;i++){
        if(fin<itv[i].second){
            fin=itv[i].first;
            ans++;
        }
    }

    cout<<ans;
}