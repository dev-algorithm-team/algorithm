#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <bits/stdc++.h>
using namespace std;

char ch[10];
bool visited[10];

string maxAns, minAns;

bool isPossible(char ch, int a, int b) {
	if (ch == '<') return a < b;
	else return a > b;
}

void solve(int n, string s) {
	int cur = s.size();
	if (cur - 1 == n) {
		maxAns = max(maxAns, s);
		minAns = min(minAns, s);
	} else {
		for (int i = 0; i <= 9; ++i) {
			if (visited[i]) continue;
			if (isPossible(ch[cur - 1], s.back() - '0', i)) {
				visited[i] = true;
				solve(n, s + (char)('0' + i));
				visited[i] = false;
			}
		}
	}
}

int main() {
	fastio;

	int k;
	cin >> k;
	for (int i = 0; i < k; ++i)
		cin >> ch[i];
	maxAns = string(k, '0');
	minAns = string(k, '9');

	for (int i = 0; i <= 9; ++i) {
		visited[i] = true;
		solve(k, string(1, '0' + i));
		visited[i] = false;
	}

	cout << maxAns << '\n';
	cout << minAns << '\n';
}
