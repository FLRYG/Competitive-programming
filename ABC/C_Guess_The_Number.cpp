#include <iostream>
using namespace std;

const int INF=1000;

int N,M;
int C[3]={INF,INF,INF};

int pow10(int x){
	if(x==0) return 1;
	else return 10*pow10(x-1);
}

int main(){
	cin>>N>>M;
	bool b=true;
	for(int i=0;i<M;i++){
		int s;
		int c;
		cin>>s>>c;
		if(C[s-1]==INF || C[s-1]==c){
			C[s-1]=c;
		}else{
			b=false;
		}
	}

	if(!b){
		cout<<-1<<endl;
		return 0;
	}
	if(C[3-N]==0){
		cout<<-1<<endl;
		return 0;
	}

	if(C[3-N]==INF){
		C[3-N]=1;
	}

	int ans=0;
	for(int i=0;i<3;i++){
		if(C[i]!=INF){
			ans+=C[i]*pow10(2-i);
		}
	}

	cout<<ans<<endl;
}

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