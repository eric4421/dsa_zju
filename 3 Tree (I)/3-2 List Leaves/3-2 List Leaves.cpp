// 03-树2 List Leaves （25 分）
// Given a tree, you are supposed to list all the leaves in the order of top down, and left to right.

// It means that you should traverse the binary tree and print leaves only.

#include "iostream"
#include "cstdio"
#include "queue"

using namespace std;

const int maxn = 10;
const int null = -1;

typedef struct bintree {
	int data;
	int left;
	int right;
}bintree;

int main()
{
	int n;
	bintree tree[maxn];
	scanf("%d",&n);

	int root;
	bool is_root[maxn];
	for (int i = 0; i < n; i++) {
		is_root[i] = true;
	}

	// create bintree
	for (int i = 0; i < n; i++) {
		tree[i].data = i;
		char tmp_left, tmp_right;
		getchar();
		scanf("%c %c", &tmp_left, &tmp_right);
		if (tmp_left == '-')
			tree[i].left = null;
		else
			tree[i].left = tmp_left - '0';
		if (tmp_right == '-')
			tree[i].right = null;
		else
			tree[i].right = tmp_right - '0';
		// mark "not root"
		if (tree[i].left != -1)
			is_root[tree[i].left] = false;
		if (tree[i].right != -1)
			is_root[tree[i].right] = false;
	}

	// find root
	for (int i = 0; i < n; i++) {
		if (is_root[i] == true) {
			root = i;
			break;
		}
	}

	// level-order traversal
	queue<bintree> Q;
	bintree T;
	// leaves[]: to save leaves' data
	int leaves[maxn];
	int count = 0;
	Q.push(tree[root]);
	while (!Q.empty()) {
		T = Q.front();
		Q.pop();
		// save leaves
		if (T.left == null && T.right == null)
			leaves[count++] = T.data;
		if (T.left != null)
			Q.push(tree[T.left]);
		if (T.right != null)
			Q.push(tree[T.right]);
	}
	for (int i = 0; i < count - 1; i++) {
		printf("%d ", leaves[i]);
	}
	printf("%d", leaves[count - 1]);
	return 0;
}
