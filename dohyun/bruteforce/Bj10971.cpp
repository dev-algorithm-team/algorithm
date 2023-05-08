#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <bits/stdc++.h>
using namespace std;

int n, ans = 1e9;
int costs[10][10];
bool visited[10];

void solve(int start, int current, int visitCnt, int totalCost) {
	if (visitCnt == n) {
		if (costs[current][start] > 0)
			ans = min(ans, totalCost + costs[current][start]);
	} else {
		for (int i = 0; i < n; ++i) {
			if (!visited[i] && costs[current][i] > 0) {
				visited[i] = true;
				solve(start, i, visitCnt + 1, totalCost + costs[current][i]);
				visited[i] = false;
			}
		}
	}
}

int main() {
	fastio;

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> costs[i][j];

	visited[0] = true;
	solve(0, 0, 1, 0);
	cout << ans << '\n';
}
