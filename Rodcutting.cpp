#include<iostream>
using namespace std;

int p[102], r[102], s[102];

int main() {
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];

	for (int i = 0; i <= n; i++) r[i] = s[i] = 0;
	for (int j = 1; j <= n; j++) {
		int q = -999999;
		for (int i = 1; i <= j; i++) {
			if (q < p[i] + r[j - i]) {
				q = p[i] + r[j - i];
				s[j] = i;
			}
		}
		r[j] = q;
	}
	cout << r[n] << '\n';
	while (n > 0) {
		cout << s[n] << ' ';
		n -= s[n];
	}
	cout << '\n';
	return 0;
}