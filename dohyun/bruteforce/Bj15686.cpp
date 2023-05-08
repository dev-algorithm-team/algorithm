#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int board[50][50];
int updatedBoard[50][50];

vector<pi> chickens, houses;

int calculateChickenDistance(vector<pi> surv) {
	int sum = 0;
	for (int i = 0; i < houses.size(); ++i) {
		int hx = houses[i].first;
		int hy = houses[i].second;
		int d = 1e9;

		for (int j = 0; j < surv.size(); ++j) {
			int cx = surv[j].first;
			int cy = surv[j].second;
			int dist = abs(hx - cx) + abs(hy - cy);

			d = min(d, dist);
		}
		sum += d;
	}
	return sum;
}

int main() {
	fastio;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 2)
				chickens.push_back({i, j});
			else if (board[i][j] == 1)
				houses.push_back({i, j});
		}
	}

	int ans = INT_MAX;
	vector<bool> comb(chickens.size());
		for (int i = 0; i < m; ++i)
			comb[i] = true;
	do {
		vector<pi> surv;
		for (int i = 0; i < comb.size(); ++i)
			if (comb[i])
				surv.push_back(chickens[i]);
		ans = min(ans, calculateChickenDistance(surv));
	} while (prev_permutation(comb.begin(), comb.end()));

	cout << ans << '\n';
}
