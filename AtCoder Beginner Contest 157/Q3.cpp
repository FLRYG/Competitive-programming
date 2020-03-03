#include <iostream>

int power(int a, int b);

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
}