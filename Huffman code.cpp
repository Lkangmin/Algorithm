#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
	struct Node* L;
	struct Node* R;
	char* value;
	int cnt;
}Node;

typedef struct Heap
{
	Node** n;
	int h_size;
}Heap;

void swap_h(Heap* heap, int index, int m)
{
	Node* tmp = heap->n[index];
	heap->n[index] = heap->n[m];
	heap->n[m] = tmp;
}

void heapify(Heap* heap, int index)
{
	if (index >= 1 && index * 2 <= heap->h_size)
	{
		int m;

		if (index * 2 + 1 > heap->h_size)
			m = index * 2;
		else if (heap->n[index * 2]->cnt <= heap->n[index * 2 + 1]->cnt)
			m = index * 2;
		else
			m = index * 2 + 1;

		if (heap->n[index]->cnt > heap->n[m]->cnt)
		{
			swap_h(heap, index, m);
			heapify(heap, m);
		}
	}
}

Node* extract(Heap* heap)
{
	swap_h(heap, 1, heap->h_size);
	heap->h_size--;
	heapify(heap, 1);

	return heap->n[heap->h_size + 1];
}

void printH(Heap* heap, int N)
{
	Node** a;
	Heap* tmp = heap;
	int res = 0;

	for (int i = heap->h_size / 2; i >= 1; i--)
		heapify(heap, i);

	a = (Node**)malloc(heap->h_size * sizeof(Node*));

	for (int i = 1; i < N; i++)
	{
		a[i] = (Node*)malloc(sizeof(Node));
		a[i]->L = extract(tmp);
		a[i]->R = extract(tmp);
		a[i]->cnt = a[i]->L->cnt + a[i]->R->cnt;

		tmp->n[++tmp->h_size] = a[i];
		for (int j = tmp->h_size / 2,k = tmp->h_size; j >= 1; j /= 2) {
			if (tmp->n[j]->cnt > tmp->n[k]->cnt) {
				heapify(tmp, j);
				k = j;
			}
			else break;
		}
		res += a[i]->cnt;
	}
	printf("%d", res);
}



int main()
{
	Heap* heap;
	int N, swap = 0, fr = 0, total;

	scanf("%d", &N);

	heap = (Heap*)malloc(sizeof(Heap));
	heap->n = (Node**)malloc((N + 1) * sizeof(Node*));
	heap->h_size = N;

	for (int i = 1; i <= N; i++)
	{
		heap->n[i] = (Node*)malloc(sizeof(Node));
		heap->n[i]->value = (char*)malloc(4 * sizeof(char));
		scanf("%s %d", heap->n[i]->value, &heap->n[i]->cnt);
	}

	scanf("%d", &total);

	swap = N - 1;
	if (swap == 0) fr = total;
	while (swap > 0) {
		swap /= 2;
		fr += total;
	}
	printf("%d\n", fr);
	printH(heap, N);

	return 0;
}