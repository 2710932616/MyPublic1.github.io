#include <stdio.h>
#include <math.h>
#include <iostream>
#include <time.h>

using namespace std;

int OJLD(int m, int n)
{
	int r = m % n;
	while (r != 0)
	{
		m = n;
		n = r;
		r = m % n;
	}
	return n;
}

int LXZSJC(int m, int n)
{
	int t = min(m, n);
	while (1)
	{
		if (m % t == 0 && n % t == 0)
			break;
		t--;
	}
	return t;
}

int FJZYS(int m, int n)
{
	int i, factor = 1;
	for (i = 2; i <= m && i <= n; i++)
		while (m % i == 0 && n % i == 0)
		{
			factor *= i;
			m = m / i;
			n = n / i;
		}
	return factor;
}

int mian()
{
	int m, n;
	cin >> m;
	cin >> n;
	clock_t start, finish;
	start = clock();
	cout << "连续整数检测结果为:" << LXZSJC(m, n) << endl;
	finish = clock();
	printf("消耗时间为:%f毫秒\n\n", (double)(finish - start) / (CLOCKS_PER_SEC * 1000.0));
	start = clock();
	cout << "欧几里得除法结果为:" << OJLD(m, n) << endl;
	finish = clock();
	printf("消耗时间为:%f毫秒\n\n", (double)(finish - start) / (CLOCKS_PER_SEC * 1000.0));
	start = clock();
	cout << "分解质因数结果为:" << FJZYS(m, n) << endl;
	finish = clock();
	printf("消耗时间为:%f毫秒\n\n", (double)(finish - start) / (CLOCKS_PER_SEC * 1000.0));
	return 0;
}