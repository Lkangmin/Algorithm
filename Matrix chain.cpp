#include<iostream>
using namespace std;

int n, p[102], m[102][102], s[102][102];


int matrix() {
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n - i + 1; j++) {
			int k = i + j - 1;
			m[j][k] = 999999;
			for (int l = j; l <= k - 1; l++) {
				int q = m[j][l] + m[l + 1][k] + p[j - 1] * p[l] * p[k];
				if (q < m[j][k]) {
					m[j][k] = q;
					s[j][k] = l;
				}
			}
		}
	}
	return m[1][n];
}



void print_pa(int a, int b) {
	if (a == b) {
		cout << a << ' ';
	}
	else {
		cout << '(';
		print_pa(a, s[a][b]);
		print_pa(s[a][b] + 1, b);
		cout << ')';
	}
}



int main() {
	cin >> n;
	for (int i = 0; i <= n; i++) cin >> p[i];

	cout << matrix() << '\n';
	print_pa(1, n);
	cout << '\n';
	return 0;
}