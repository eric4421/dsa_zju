// 03-树1 树的同构 （25 分）
// 给定两棵树T1和T2。如果T1可以通过若干次左右孩子互换就变成T2，则我们称两棵树是“同构”的。现给定两棵树，请你判断它们是否是同构的。

#include "iostream"
#include "cstdio"

const int maxn = 10;
const int empty = -1;

typedef struct bintree {
	char data;
	int left;
	int right;
}bintree;

int create_bintree(bintree tree[]);
bool isomorphic(bintree tree1[], bintree tree2[], int root1, int root2);

int main()
{
	int root1, root2;
	bintree tree1[maxn], tree2[maxn];
	root1 = create_bintree(tree1);
	root2 = create_bintree(tree2);
	if (isomorphic(tree1, tree2, root1, root2) == true)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}

int create_bintree(bintree tree[]) {
	int root = empty;
	bool is_root[maxn];
	char tmp_left, tmp_right;
	int n;
	scanf("%d", &n);
	if (n <= 0)
		return root;
	for (int i = 0; i < n; i++)
		is_root[i] = true;
	for (int i = 0; i < n; i++) {
		// 注意: 不要读入回车!
		getchar();
		scanf("%c %c %c", &tree[i].data, &tmp_left, &tmp_right);
		if (tmp_left != '-') {
			tree[i].left = tmp_left - '0';
			is_root[tree[i].left] = false;
		}
		else
			tree[i].left = empty;
		if (tmp_right != '-') {
			tree[i].right = tmp_right - '0';
			is_root[tree[i].right] = false;
		}
		else
			tree[i].right = empty;
	}
	for (int i = 0; i < n; i++) {
		if (is_root[i] == true) {
			root = i;
			break;
		}
	}
	return root;
}

bool isomorphic(bintree tree1[], bintree tree2[], int root1, int root2)
{
	// 都为空: 同构
	if (root1 == empty && root2 == empty)
		return true;
	// 一棵树为空: 异构
	if ((root1 != empty && root2 == empty) || (root1 == empty && root2 != empty))
		return false;
	// 根节点不同: 异构
	if (tree1[root1].data != tree2[root2].data)
		return false;
	// 都没有左树: 检查右树
	if (tree1[root1].left == empty && tree2[root2].left == empty)
		return isomorphic(tree1, tree2, tree1[root1].right, tree2[root2].right);
	// 左树不空且左树的根相同: 向下比较
	if (tree1[root1].left != empty && tree2[root2].left != empty && tree1[tree1[root1].left].data == tree2[tree2[root2].left].data)
		return(isomorphic(tree1, tree2, tree1[root1].left, tree2[root2].left) && isomorphic(tree1, tree2, tree1[root1].right, tree2[root2].right));
	// 两棵左树不同: 交换
	else
		return(isomorphic(tree1, tree2, tree1[root1].left, tree2[root2].right) && isomorphic(tree1, tree2, tree1[root1].right, tree2[root2].left));
}
