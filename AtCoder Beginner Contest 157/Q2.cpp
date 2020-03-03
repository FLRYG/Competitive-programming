#include <iostream>

int main()
{
	int bingo[3][3];
	int N;
	int* x;
	bool tf[3][3] = { {0,0,0} ,{0,0,0}, {0,0,0} };

	for(int i = 0; i < 3;i++)
	{
		std::cin >> bingo[i][0] >> bingo[i][1] >> bingo[i][2];
	}

	std::cin >> N;
	x = new int[N];

	for (int n = 0; n < N; n++)
	{
		std::cin >> x[n];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (x[n] == bingo[i][j])
				{
					tf[i][j] = 1;
				}
			}
		}
	}



	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum = 0;
		for (int j = 0; j< 3; j++)
			sum += tf[i][j];
		if (sum == 3)
		{
			std::cout << "Yes";
			return 0;
		}
	}
	
	sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum = 0;
		for (int j = 0; j < 3; j++)
			sum += tf[j][i];
		if (sum == 3)
		{
			std::cout << "Yes";
			return 0;
		}
	}
	
	sum = tf[0][0] + tf[1][1] + tf[2][2];
	if (sum == 3)
	{
		std::cout << "Yes";
		return 0;
	}

	sum = tf[0][2] + tf[1][1] + tf[2][0];
	if (sum == 3)
	{
		std::cout << "Yes";
		return 0;
	}


	std::cout << "No";
}