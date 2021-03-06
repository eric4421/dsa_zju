// 01-复杂度2 Maximum Subsequence Sum（25 分）
// Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence. 

#include "iostream"
#include "vector"
using namespace std;

long long max_subseq_sum(int k, vector<int> a, int &front, int &end) {
	long long temp = 0, res = 0;
	int temp_front = 0;
	for (int i = 0; i < k; i++) {
		temp += a[i];	
		if (temp > res) {
			res = temp;
			front = temp_front;
			end = i;
		}
		else if (temp < 0) {
			temp = 0;
			temp_front = i + 1;
		}
	}
	return res;
}

int main()
{
	int K;
	scanf("%d", &K);

	vector<int> a(K);
	bool all_negative = true;
	bool no_positive = true;
	for (int i = 0; i < K; i++) {
		scanf("%d", &a[i]);
		if (a[i] >= 0) {
			all_negative = false;
		}
		if (a[i] > 0) {
			no_positive = false;
		}
	}
	
	if (all_negative) {
		printf("%d %d %d\n", 0, a[0], a[K - 1]);
		return 0;
	}
	else if (no_positive) {
		for (int i = 0; i < K; i++) {
			if (a[i] == 0) {
				printf("%d %d %d\n", 0, a[i], a[i]);
				return 0;
			}
		}
	}

	long long res;
	int front, end;
	res = max_subseq_sum(K, a, front, end);
	printf("%lld %d %d\n", res, a[front], a[end]);
	return 0;
}