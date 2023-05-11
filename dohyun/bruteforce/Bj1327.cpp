#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

vector<int> arr;
int n, k;

int bfs() {
	map<vector<int>, int> dist;
	dist[arr] = 0;

	vector<int> sorted = arr;
	sort(all(sorted));

	queue<vector<int>> q;
	q.push(arr);

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (cur == sorted)
			return dist[cur];

		for (int i = 0; i + k <= n; ++i) {
			vector<int> next = cur;
			reverse(next.begin() + i, next.begin() + i + k);
			if (!dist.count(next)) {
				dist[next] = dist[cur] + 1;
				q.push(next);
			}
		}
	}
	return -1;
}

int main() {
	fastio;

	cin >> n >> k;
	arr = vector<int>(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	cout << bfs();
}
