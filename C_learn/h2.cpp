#include <iostream>
#include<math.h>
using namespace std;
bool iPrime(int n)
{

	int sqrtNum;
	bool m = true;
	if (2 > n||(2 != n&&n%2 == 0))
	{
		m = false;
		return m;
	}
	sqrtNum = sqrt(n);

	for (int j = 3; j <= sqrtNum; j++)
	{
		if (0 == n % j )
		{
			m = false;
			break;
		}
	}
	return m;
}

int main()
{
	int N;
	cin >> N;
	for (int i = 2; i <= N / 2; i++)
	{
		int j = N - i;
		if (iPrime(i) && iPrime(j))
		{
			cout << N << " = " << i << " + " << j << endl;
			break;
		}
	}
	return 0;
}
