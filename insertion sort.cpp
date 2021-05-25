#include<stdio.h>

int main() {
	int n;
	int v[30000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	for (int i = 1; i < n; i++) {
		int key = v[i];
		int j = i - 1;
		while (j >= 0 && v[j] > key) {
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = key;
	}

	for (int i = n - 1; i > -1; i--)
		printf("%d\n", v[i]);
	return 0;
}