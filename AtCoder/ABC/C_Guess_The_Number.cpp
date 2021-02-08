#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N,M;
int s[5],c[5];

int main(){
	cin>>N>>M;
	rep(i,M) cin>>s[i]>>c[i];

	if(N==1){
		bool b=true;
		rep(i,M) b&=c[i]==0;
		if(b){
			cout<<0<<endl;
			return 0;
		}
	}

	int n=1;
	rep(i,N) n*=10;

	int ans=-1;
	for(int i=n/10;i<n;i++){
		bool b=true;
		rep(j,M){
			int x=i;
			rep(k,N-s[j]) x/=10;
			b&=x%10==c[j];
		}
		if(b){
			ans=i;
			break;
		}
	}

	cout<<ans<<endl;
	
	return 0;
}

// #include <iostream>
// using namespace std;

// const int INF=1000;

// int N,M;
// int C[3]={INF,INF,INF};

// int pow10(int x){
// 	if(x==0) return 1;
// 	else return 10*pow10(x-1);
// }

// int main(){
// 	cin>>N>>M;
// 	bool b=true;
// 	for(int i=0;i<M;i++){
// 		int s;
// 		int c;
// 		cin>>s>>c;
// 		if(C[s-1+3-N]==INF || C[s-1+3-N]==c){
// 			C[s-1+3-N]=c;
// 		}else{
// 			b=false;
// 		}
// 	}

// 	if(!b){
// 		cout<<-1<<endl;
// 		return 0;
// 	}
// 	if(C[3-N]==0 && N>1){
// 		cout<<-1<<endl;
// 		return 0;
// 	}

// 	if(C[3-N]==INF && N>1){
// 		C[3-N]=1;
// 	}

// 	int ans=0;
// 	for(int i=0;i<3;i++){
// 		if(C[i]!=INF){
// 			ans+=C[i]*pow10(2-i);
// 		}
// 	}

// 	cout<<ans<<endl;
// }

/*int power(int a, int b);

int main()
{
	int N;
	int M;
	int* s;
	int* c;
	int ans=0;

	std::cin >> N >> M;

	s = new int[M];
	c = new int[M];

	for (int i = 0; i < M; i++)
	{
		std::cin >> s[i] >> c[i];
	}

	if (N >= 2) 
	{
		for (int i = 0; i < M; i++)
		{
			if (s[i] == 1 && c[i] == 0)
			{
				ans = -1;
				goto out;
			}

			for (int j = 0; j < M; j++)
			{
				if (i == j)
				{
					continue;
				}
				if (s[i] == s[j] && c[i] != c[j])
				{
					ans = -1;
					goto out;
				}
				else if (s[i] == s[j] && c[i] == c[j])
				{
					s[j] = -1;
					c[j] = -1;
				}
			}
			if (s[i]!=-1)
				ans += power(10, N - s[i]) * c[i];
		}
	}
	else
	{
		for (int i = 0; i < M; i++)
		{
			bool a = true;
			for (int j = 0; j < M; j++)
			{
				if (i == j)
				{
					continue;
				}
				if (s[i] == s[j] && c[i] != c[j])
				{
					ans = -1;
					goto out;
				}
				else if (s[i] == s[j] && c[i] == c[j])
				{
					s[j] = -1;
					c[j] = -1;
				}
			}
			if (s[i] != -1)
				ans += power(10, N - s[i]) * c[i];
		}
	}

	if (power(10, N - 1) > ans) {
		ans += power(10, N - 1);
	}
out:
	std::cout << ans;

	return 0;
}

int power(int a, int b)
{
	int res = 1;
	for (int i = 0; i < b; i++) {
		res *= a;
	}
	return res;
}*/