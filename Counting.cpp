#include<iostream>
using namespace std;

int ar[2][100001];
int key[100001];
int c[100001];

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) 	cin >> ar[0][i] >> ar[1][i];
	for (int i = 0; i < n; i++)		cin >> key[i];
	for (int i = 0; i < n; i++)		c[key[i]]++;
	for (int i = 0; i <= m; i++	)	c[i] = c[i] + c[i - 1];
	for (int i = 0; i < k; i++)		cout << c[ar[1][i]] - c[ar[0][i] - 1] << '\n';
	return 0;
}