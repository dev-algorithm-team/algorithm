#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <bits/stdc++.h>
using namespace std;

int d[100'001];

int main() {
	fastio;

	int n;
	cin >> n;
	d[2] = 3;
	for (int i = 4; i <= n; i += 2) {
		d[i] = d[2] * d[i - 2] + 2;
		for (int j = 4; j <= i; j += 2)
			d[i] += d[i - j] * 2;
	}
	cout << d[n];
}
