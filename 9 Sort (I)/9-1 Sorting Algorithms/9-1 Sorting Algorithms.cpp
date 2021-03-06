// 9-1 Sorting Algorithms.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 09-排序1 排序 （25 分）
// 给定N个（长整型范围内的）整数，要求输出从小到大排序后的结果。

#include "iostream"
#include "cstdio"
#include "cstdlib"

// merge sort (time: O(nlog2n), space: O(n))
void merge(int* a, int low, int mid, int high) {
	int i, j, k;
	int* b = (int*)malloc(sizeof(int)*(high + 1));
	for (i = low; i <= high; i++)
		b[i] = a[i];
	for (i = low, j = low, k = mid+1; j <= mid && k <= high; i++) {
		if (b[j] <= b[k])
			a[i] = b[j++];
		else
			a[i] = b[k++];
	}
	while (j <= mid) a[i++] = b[j++];
	while (k <= high) a[i++] = b[k++];

	free(b);
}

void merge_sort(int* a, int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		merge_sort(a, low, mid);
		merge_sort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	int* a = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	merge_sort(a, 0, N - 1);
	for (int i = 0; i < N - 1; i++)
		printf("%d ", a[i]);
	printf("%d", a[N - 1]);
	free(a);
	return 0;
}
