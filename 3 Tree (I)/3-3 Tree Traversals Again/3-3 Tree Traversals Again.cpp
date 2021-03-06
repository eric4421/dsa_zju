// 03-树3 Tree Traversals Again （25 分）
// An inorder binary tree traversal can be implemented in a non-recursive way with a stack.
// Your task is to give the postorder traversal sequence of this tree.

/*
	思路
	1. Push 得到先序遍历序列, Pop 得到中序遍历序列
	2. 前序遍历序列第一个元素是根节点, 后序遍历序列最后一个元素是根节点
	3. 在中序遍历中, 根节点的两边可以分出左子树和右子树, 对左子树和右子树分别做递归, 可以重建二叉树
*/

#include "iostream"
#include "cstdio"
#include "string"

const int maxn = 30;

void get_post_seq(int pre_seq[], int in_seq[], int post_seq[], int pre_left, int in_left, int post_left, int n);

int main()
{
	int pre_seq[maxn]; int in_seq[maxn]; int post_seq[maxn];
	// stack0: simulate "push" and "pop" operations
	int stack0[maxn]; 
	// top0: top of stack0; n0: counter of pre_seq; top1: top of in_seq (regarded as stack)
	int top0 = -1, n0 = 0, top1 = -1;

	int n; scanf("%d", &n);
	if (n == 0) return 0;

	std::string str; str.resize(5);
	std::string str1 = "Push"; str1.resize(5);
	std::string str2 = "Pop"; str2.resize(5);
	for (int i = 0; i < n * 2; i++) {
		int temp; 
		scanf("%s", &str[0]);
		if (str == str1) {
			scanf("%d", &temp);
			stack0[++top0] = temp;
			pre_seq[n0++] = temp;
		}
		if (str == str2) {
			in_seq[++top1] = stack0[top0--];
		}
	}

	get_post_seq(pre_seq, in_seq, post_seq, 0, 0, 0, n);

	for (int i = 0; i < n - 1; i++) {
		printf("%d ", post_seq[i]);
	}
	printf("%d", post_seq[n - 1]);
	
	return 0;
}

void get_post_seq(int pre_seq[], int in_seq[], int post_seq[], int pre_left, int in_left, int post_left, int n) {
	if (n == 0) return;
	if (n == 1) {
		post_seq[post_left] = pre_seq[pre_left];
		return;
	}

	int root = pre_seq[pre_left];
	post_seq[post_left + n - 1] = root;

	int i = 0;
	for (; i < n; i++) {
		if (in_seq[in_left + i] == root)
			break;
	}
	int left = i, right = n - left - 1;
	get_post_seq(pre_seq, in_seq, post_seq, pre_left + 1, in_left, post_left, left);
	get_post_seq(pre_seq, in_seq, post_seq, pre_left + i + 1, in_left + left + 1, post_left + left, right);
	return;
}