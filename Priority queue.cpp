#include<stdio.h>
int n, k, heap[100001], count;

void swap(int* a1, int* a2) {
	int tmp = *a1;
	*a1 = *a2;
	*a2 = tmp;
}

void insert(int x) {
	heap[++count] = x;
	int t = count;
	while (t != 1) {
		if (heap[t] > heap[t / 2]) swap(&heap[t], &heap[t / 2]), t /= 2;
		else break;
	}
}

int pop() {
	int ret = heap[1],index = 1;
	heap[1] = heap[count];
	heap[count--] = 0;

	while (1) {
		if (index * 2 > count) break;
		if (heap[index] >= heap[index * 2] && heap[index] >= heap[index * 2 + 1]) break;
		if (heap[index * 2] > heap[index * 2 + 1]) swap(&heap[index], &heap[index * 2]), index *= 2;
		else swap(&heap[index], &heap[index * 2 + 1]), index = index * 2 + 1;
	}

	return ret;
}

void restore(int idx) {
	if (idx != 1 && heap[idx / 2] < heap[idx]) {
		while (idx != 1) {
			if (heap[idx] > heap[idx / 2]) swap(&heap[idx], &heap[idx / 2]), idx /= 2;
			else break;
		}
	}
	else {
		while (1) {
			if (idx * 2 > count) break;
			if (heap[idx] >= heap[idx * 2] && heap[idx] >= heap[idx * 2 + 1]) break;
			if (heap[idx * 2] > heap[idx * 2 + 1]) swap(&heap[idx], &heap[idx * 2]), idx *= 2;
			else swap(&heap[idx], &heap[idx * 2 + 1]), idx = idx * 2 + 1;
		}
	}
}

int main() {
	while (1) {
		int a, b, c;
		scanf("%d", &a);
		if (a == 0) break;
		switch (a)
		{
		case 1:
			scanf("%d", &b);
			insert(b);
			break;
		case 2:
			printf("%d ", pop());
			break;
		case 3:
			scanf("%d%d", &b, &c);
			heap[b] = c;
			restore(b);
			break;
		}
	}
	printf("\n");
	for (int i = 1; i <= count; i++) printf("%d ", heap[i]);
	printf("\n");
	return 0;
}