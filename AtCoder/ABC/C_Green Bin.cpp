#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <map>
#include <unordered_map>
#include <iterator>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int N;
unordered_map<string,int> S;

int main(){
    ll ans=0;

    cin>>N;
    rep(i,N){
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        S[s]++;
        ans+=S[s]-1;
    }
    
    cout<<ans<<endl;
}