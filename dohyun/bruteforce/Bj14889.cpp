#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#include <bits/stdc++.h>
using namespace std;
#define IS_IN_TEAM_A(i, j) (i & (1 << j))

int S[20][20];

int main() {
	fastio;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> S[i][j];

	int ans = 1e9;
	for (int i = (1 << n) - 1; i > 0; --i) {
		if (__builtin_popcount(i) != n / 2) continue;

		int teamA = 0, teamB = 0;
		for (int j = 0; j < n; ++j) {
			for (int k = j + 1; k < n; ++k) {
				if (IS_IN_TEAM_A(i, j) && IS_IN_TEAM_A(i, k))
					teamA += S[j][k] + S[k][j];
				else if (!IS_IN_TEAM_A(i, j) && !IS_IN_TEAM_A(i, k))
					teamB += S[j][k] + S[k][j];
			}
		}

		ans = min(ans, abs(teamA - teamB));
	}
	cout << ans;
}
