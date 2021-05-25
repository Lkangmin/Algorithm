#include<iostream>
using namespace std;

bool tmp[100001];

int main() {
	int n, m, k, res = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> k;
		tmp[k] = true;
	}
	for (int i = 0; i < m; i++) {
		cin >> k;
		if (tmp[k]) res++;
	}
	cout << res << '\n';
	return 0;
}