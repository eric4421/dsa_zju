// 04-树7 二叉搜索树的操作集 （30 分）
// 本题要求实现给定二叉搜索树的5种常用操作。

#include "iostream"
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

void PreorderTraversal(BinTree BT) /* 先序遍历 */
{
	if (BT == NULL) return;
	printf(" %d", BT->Data);
	PreorderTraversal(BT->Left);
	PreorderTraversal(BT->Right);
}

void InorderTraversal(BinTree BT) /* 中序遍历 */
{
	if (BT == NULL) return;
	InorderTraversal(BT->Left);
	printf(" %d", BT->Data);
	InorderTraversal(BT->Right);
}

BinTree Insert(BinTree BST, ElementType X);
BinTree Delete(BinTree BST, ElementType X);
Position Find(BinTree BST, ElementType X);
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);

int main()
{
	BinTree BST, MinP, MaxP, Tmp;
	ElementType X;
	int N, i;

	BST = NULL;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &X);
		BST = Insert(BST, X);
	}
	printf("Preorder:"); PreorderTraversal(BST); printf("\n");
	MinP = FindMin(BST);
	MaxP = FindMax(BST);
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &X);
		Tmp = Find(BST, X);
		if (Tmp == NULL) printf("%d is not found\n", X);
		else {
			printf("%d is found\n", Tmp->Data);
			if (Tmp == MinP) printf("%d is the smallest key\n", Tmp->Data);
			if (Tmp == MaxP) printf("%d is the largest key\n", Tmp->Data);
		}
	}
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &X);
		BST = Delete(BST, X);
	}
	printf("Inorder:"); InorderTraversal(BST); printf("\n");

	return 0;
}
/* 你的代码将被嵌在这里 */
BinTree Insert(BinTree BST, ElementType X) {
	if (BST == NULL) {
		BST = (BinTree)malloc(sizeof(struct TNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else {
		if (X < BST->Data)
			BST->Left = Insert(BST->Left, X);
		else if (X > BST->Data)
			BST->Right = Insert(BST->Right, X);
	}
	return BST;
}

BinTree Delete(BinTree BST, ElementType X) {
	Position temp;
	if (BST == NULL) {
		printf("Not Found\n");
		return BST;
	}
	if (X < BST->Data)
		BST->Left = Delete(BST->Left, X);
	else if (X > BST->Data)
		BST->Right = Delete(BST->Right, X);
	else {
		if (BST->Left && BST->Right) {
			temp = FindMin(BST->Right);
			BST->Data = temp->Data;
			BST->Right = Delete(BST->Right, BST->Data);
		}
		else {
			temp = BST;
			if (!BST->Left) BST = BST->Right;
			else BST = BST->Left;
			free(temp);
		}
	}
	return BST;
}

Position Find(BinTree BST, ElementType X) {
	if (BST == NULL) return BST;
	if (X < BST->Data)
		return Find(BST->Left, X);
	else if (X > BST->Data)
		return Find(BST->Right, X);
	else
		return BST;
}

Position FindMin(BinTree BST) {
	if (BST == NULL) return BST;
	if (BST->Left == NULL) return BST;
	return FindMin(BST->Left);
}

Position FindMax(BinTree BST) {
	if (BST == NULL) return BST;
	if (BST->Right == NULL) return BST;
	return FindMax(BST->Right);
}
