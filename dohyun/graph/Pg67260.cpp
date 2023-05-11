#include <bits/stdc++.h>
using namespace std;
using ti4 = tuple<int, int, int, int>;

const int INF = 1e9;
int dist[25][25][4];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int solution(vector<vector<int>> board) {
	int n = board.size();
	fill(&dist[0][0][0], &dist[24][24][3] + 1, INF);

	priority_queue<ti4> pq;
	for (int i = 0; i < 4; ++i) {
		dist[0][0][i] = 0;
		pq.push({0, 0, 0, i}); // {비용, X, Y, 방향}
	}

	while (!pq.empty()) {
		auto [cost, cx, cy, dir] = pq.top();
		pq.pop();

		if (dist[cx][cy][dir] < cost)
			continue;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (!(nx >= 0 && nx < n && ny >= 0 && ny < n)) continue;
			if (board[nx][ny] == 1) continue;

			int nextCost = (dir == i ? cost + 100 : cost + 600);
			if (dist[nx][ny][i] > nextCost) {
				dist[nx][ny][i] = nextCost;
				pq.push({nextCost, nx, ny, i});
			}
		}
	}

	int ans = INF;
	for (int i = 0; i < 4; ++i)
		ans = min(ans, dist[n - 1][n - 1][i]);
    return ans;
}
