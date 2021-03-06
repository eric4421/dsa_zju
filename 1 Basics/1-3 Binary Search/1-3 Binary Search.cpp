// 01-复杂度3 二分查找（20 分）本题要求实现二分查找算法。题目保证传入的数据是递增有序的。
// 注意：元素从下标1开始存储

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch(List L, ElementType X);

int main()
{
	List L;
	ElementType X;
	Position P;

	L = ReadInput();
	scanf("%d", &X);
	P = BinarySearch(L, X);
	printf("%d\n", P);

	return 0;
}

/* 你的代码将被嵌在这里 */
Position BinarySearch(List L, ElementType X) {
	Position low = 1;
	Position high = L->Last;
	Position mid = (low + high) / 2;
	while (high >= 1) {
		mid = (low + high) / 2;
		if (X < L->Data[mid])
			high = mid - 1;
		else if (X > L->Data[mid])
			low = mid + 1;
		else
			return mid;
	}
	return NotFound;
}

/* 裁判实现 */
List ReadInput() {
	LNode *L = new LNode;
	scanf("%d", &L->Last);
	L->Data[0] = 0;
	int i;
	for (i = 1; i <= L->Last; i++)
		scanf("%d", &L->Data[i]);
	return L;
}