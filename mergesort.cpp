#include<iostream>
using namespace std;

int sorted[100000];

void merge(int* a, int p, int q, int r) {
	int i = p;
	int j = q + 1;
	int k = p;
	while (i <= q && j <= r) {
		if (a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	if (i > q) {
		for (int t = j; t <= r; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= q; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	for (int t = p; t <= r; t++)
		a[t] = sorted[t];
}

void mergesort(int* a, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		mergesort(a, p, q);
		mergesort(a, q + 1, r);
		merge(a, p, q, r);
	}
}


int main() {
	int n;
	int a[100000];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	mergesort(a, 0, n - 1);
	for (int i = n - 1; i > -1; i--)
		cout << a[i] << '\n';
	return 0;
}