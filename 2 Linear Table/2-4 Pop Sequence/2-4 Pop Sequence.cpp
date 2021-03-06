// 02-线性结构4 Pop Sequence （25 分）
// Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly. 
// You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack.

#include "iostream"
#include "cstdio"

const int maxm = 1000;
const int empty = -2;

typedef struct stack {
	int data[maxm];
	int top;
	int size;
}stack;

void stack_create(stack &s, int m);
void stack_push(stack &s, int x);
int stack_pop(stack &s);
void stack_clear(stack &s);
bool stack_empty(stack s);
int stack_top(stack s);
bool is_pop_sequence(stack &s, int pop_seq[], int m, int n);

int main()
{
	int m, n, k;
	stack s;
	int pop_seq[maxm];
	bool flag[maxm];
	scanf("%d %d %d", &m, &n, &k);
	stack_create(s, m);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &pop_seq[j]);
		}
		flag[i] = is_pop_sequence(s, pop_seq, m, n);
	}
	for (int i = 0; i < k; i++) {
		printf(flag[i] ? "YES\n" : "NO\n");
	}
	return 0;
}

void stack_create(stack &s, int m) {
	s.size = m;
	s.top = -1;
	return;
}

void stack_push(stack &s, int x) {
	if (s.top < s.size - 1) {
		s.data[++s.top] = x;
	}
	return;
}

int stack_pop(stack &s) {
	if (s.top > -1) {
		return s.data[s.top--];
	}
	return empty;
}

void stack_clear(stack &s) {
	s.top = -1;
	return;
}

bool stack_empty(stack s){
	if (s.top > -1) {
		return false;
	}
	return true;
}

int stack_top(stack s) {
	if (s.top > -1) {
		return s.data[s.top];
	}
	return empty;
}

bool is_pop_sequence(stack &s, int pop_seq[], int m, int n) {
	int first = 0;
	for (int i = 1; i <= n; i++) {
		// if stack is full...
		if (s.top == s.size - 1) {
			stack_clear(s);
			return false;
		}
		stack_push(s, i);
		while (stack_top(s) == pop_seq[first]) {
			stack_pop(s);
			first++;
		}
	}
	stack_clear(s);
	if (first < n) {
		return false;
	}
	return true;
}
