#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int H,W,K;
vector<string> S(10);

int main(){
    cin>>H>>W>>K;
    rep(i,H) cin>>S[i];

    int ans=100100100;
    for(int n=0;n<1<<(H-1);n++){
        int group=0;
        vector<int> id(H);
        for(int i=0;i<H;i++){
            id[i]=0;
            if(n>>i&1) group++;
        }

        int res=group;
        vector<int> white(group);
        fill(white.begin(),white.end(),0);
        bool first=true;
        cout<<"n="<<n<<endl;
        for(int j=0;j<W;j++){
            for(int i=0;i<H;i++){
                cout<<"  (i,j)=("<<i<<","<<j<<")"<<endl;
                if(S[i][j]=='1'){
                    white[id[i]]++;
                    cout<<"     white["<<id[i]<<"]="<<white[id[i]]<<endl;
                    if(white[id[i]]>K && first){
                        goto a;
                    }else if(white[id[i]]>K){
                        j--;
                        res++;
                        fill(white.begin(),white.end(),0);
                        first=true;
                        cout<<"  <|="<<j+1<<">"<<endl;
                        goto b;
                    }
                }
            }
            first=false;
            b:;
        }
        ans=min(ans,res);
        a:;
        cout<<"[ans="<<ans<<"]"<<endl;
    }

    cout<<ans<<endl;
}

/*int H,W,K;
int S[10][1000];
int white[10];

int bitCount(int x){
    int res=0;
    while(x>0){
        if(x%2==1) res++;
        x/=2;
    }
    return res;
}

int main(){
    cin>>H>>W>>K;
    for(int i=0;i<H;i++){
        int x;
        cin>>x;
        for(int j=W-1;j>=0;j--){
            S[i][j]=x%10;
            x/=10;
        }
    }

    int ans=100100100;
    for(int n=0;n<(1<<(H-1));n++){
        int res=bitCount(n);
        int divNum=0;
        bool first=true;
        fill(white,white+10,0);
        //cout<<"n="<<n<<endl;
        for(int j=0;j<W;j++){
            //cout<<" j="<<j<<endl;
            for(int i=0;i<H;i++){
                //cout<<"  (i,j)=("<<i<<","<<j<<")"<<endl;
                if(S[i][j]==1){
                    white[divNum]++;
                    //cout<<"     white["<<divNum<<"]="<<white[divNum]<<endl;
                    if(white[divNum]>K && first){
                        goto a;
                    }else if(white[divNum]>K){
                        j--;
                        res++;
                        divNum=0;
                        first=true;
                        fill(white,white+10,0);
                        //cout<<"  <|="<<j+1<<">"<<endl;
                        goto b;
                    }
                }
                if(n&(1<<(i))){
                    divNum++;
                    //cout<<"     divNum++"<<endl;
                } 
            }
            divNum=0;
            first=false;
            b:;
        }
        ans=min(res,ans);
        a:;
        //cout<<"[ans="<<ans<<"]"<<endl;
    }

    cout<<ans<<endl;
}*/