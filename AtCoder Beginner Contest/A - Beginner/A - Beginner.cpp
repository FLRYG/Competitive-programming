#include <iostream>
using namespace std;

int main()
{
	int N,R;
	cin >> N >> R;

	int res;
	if (N >= 10)
	{
		res = R;
	}
	else 
	{
		res = R + 100 * (10 - N);
	}

	cout << res;
}
