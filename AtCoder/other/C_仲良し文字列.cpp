#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

string A,B;
int N;

void swap(char &a, char &b){
    char c=a;
    a=b;
    b=c;
}

int main(){
    cin>>A>>B;
    N=A.size();

    string s,t;
    rep(i,N){
        if(A[i]!=B[i]){
            s+=A[i];
            t+=B[i];
        }
    }

    vector<int> cnt(26);
    rep(i,N){
        cnt[A[i]-'a']++;
    }

    int n=s.size();
    if(n>6){
        cout<<"NO"<<endl;
        return 0;
    }else{
        rep(i,26){
            if(cnt[i]>=2){
                char c='a'+i;
                s+=c;
                s+=c;
                t+=c;
                t+=c;
                n+=2;
                break;
            }
        }
    }

    rep(i1,n){
        string s1=s;
        rep(j1,n){
            if(i1==j1) continue;
            string t1=s1;
            t1[i1]=s1[j1];
            t1[j1]=s1[i1];
            rep(i2,n){
                string s2=t1;
                rep(j2,n){
                    if(i2==j2) continue;
                    string t2=s2;
                    t2[i2]=s2[j2];
                    t2[j2]=s2[i2];
                    rep(i3,n){
                        string s3=t2;
                        rep(j3,n){
                            if(i3==j3) continue;
                            string t3=s3;
                            t3[i3]=s3[j3];
                            t3[j3]=s3[i3];
                            if(t3==t){
                                cout<<"YES"<<endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    cout<<"NO"<<endl;
}