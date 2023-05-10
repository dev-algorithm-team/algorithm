#include <iostream>
using namespace std;

int n, s, ans, a[20];

void solve(int i, int sum) {
	if (i == n) {
		if (sum == s) ans++;
		return;
	}
	solve(i + 1, sum + a[i]);
	solve(i + 1, sum);
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	solve(0, 0);
	if (s == 0) ans--;
	cout << ans << '\n';
}
