#include<iostream>
using namespace std;


int main() {
	int n;
	int a1[104], a2[104];
	int t1[104], t2[104];
	int s[3][104];
	int T[3][104];
	int sol[104];
	int x1, x2, e1, e2;

	cin >> n;
	cin >> e1 >> e2;
	cin >> x1 >> x2;
	for (int i = 1; i <= n; i++) cin >> a1[i];
	for (int i = 1; i <= n; i++) cin >> a2[i];
	for (int i = 1; i < n; i++) cin >> t1[i];
	for (int i = 1; i < n; i++) cin >> t2[i];

	T[1][1] = e1 + a1[1];
	T[2][1] = e2 + a2[1];

	for (int i = 2; i <= n; i++) {
		if (T[1][i - 1] <= T[2][i - 1] + t2[i - 1]) {
			T[1][i] = T[1][i - 1] + a1[i];
			s[1][i] = 1;
		}
		else {
			T[1][i] = T[2][i - 1] + t2[i - 1] + a1[i];
			s[1][i] = 2;
		}

		if (T[2][i - 1] <= T[1][i - 1] + t1[i - 1]) {
			T[2][i] = T[2][i - 1] + a2[i];
			s[2][i] = 2;
		}
		else {
			T[2][i] = T[1][i - 1] + t1[i - 1] + a2[i];
			s[2][i] = 1;
		}
	}
	T[1][n + 1] = T[1][n] + x1;
	T[2][n + 1] = T[2][n] + x2;

	if (T[1][n + 1] <= T[2][n + 1]) sol[n + 1] = 1;
	else sol[n + 1] = 2;

	int cur = sol[n+1];
	for (int i = n; i >= 1; i--) {
		cur = s[cur][i];
		sol[i] = cur;
	}
	if (T[1][n + 1] <= T[2][n + 1]) cout << T[1][n + 1]<<'\n';
	else cout << T[2][n + 1]<<'\n';

	for (int i = 2; i <= n + 1; i++)
		cout << sol[i] << ' ' << i - 1 << '\n';

	return 0;
}