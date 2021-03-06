// 01-复杂度1 最大子列和问题（20 分）现要求你编写程序，计算给定整数序列的最大子列和。

#include "iostream"
#include "cstdio"

const int maxk = 100001;

long long max_subseq_sum_linear(int k, int a[]) {
	long long temp = 0, res = 0;
	for (int i = 0; i < k; i++) {
		temp += *(a + i);
		if (temp > res) {
			res = temp;
		}
		else if (temp < 0) {
			temp = 0;
		}
	}
	return res;
}

int main()
{
	int K, a[maxk];
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &a[i]);
	}
	printf("%lld\n", max_subseq_sum_linear(K, a));
	system("pause");
	return 0;
}

