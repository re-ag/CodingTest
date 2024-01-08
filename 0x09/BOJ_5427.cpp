#include <bits/stdc++.h>
using namespace std;
/*
	BOJ 5427 불
	https://www.acmicpc.net/problem/5427

 3 3
 ...
 .@.
 ...
 ans = 2 / my = impossible
*/

int test, n, m;
string board[1001];
int dist[1001][1001];
int dist2[1001][1001];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int main() {
	queue<pair<int, int>> q;

	queue<pair<int, int>> q2;
	cin >> test;
	while (test--) {
		cin >> m >> n;
		while (!q.empty()) q.pop();
		while (!q2.empty()) q2.pop();
		for (int i = 0; i < n; i++) {
			fill(dist[i], dist[i] + m, 0);
			fill(dist2[i], dist2[i] + m, 0);
		}
		for (int i = 0; i < n; i++) {
			cin >> board[i];
			for (int j = 0; j < m; j++) {
				if (board[i][j] == '*') {
					q.push({ i,j });
					dist[i][j] = 1; // 시작점은 1로
				}
				else if (board[i][j] == '@') {
					q2.push({ i,j });
					dist2[i][j] = 1; // 시작점은 1로
				}
				else if (board[i][j] == '#') {
					dist[i][j] = dist2[i][j] = -1; // 갈 수 없는 길은 -1로
				}
			}
		}
		// dist나 dist2나 방문할 수 있는 곳만 0으로 처리, 즉 bfs 순회시 0이 아닌곳은 continue;
		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (dist[nx][ny] != 0) continue;
				q.push({ nx,ny });
				dist[nx][ny] = dist[cur.first][cur.second] + 1;
			}
		}

		bool flag = true;
		while (!q2.empty() && flag) {
			auto cur = q2.front(); q2.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) { // 탈출!
					cout << dist2[cur.first][cur.second] << '\n';
					flag = false;
					break;
				}
				// dist[nx][ny] > 0면서 dist2[cur.first][cur.second] + 1 >=dist[nx][ny] 여야 한다
				// 왜냐하면 불이 아예 없을 때에는 dist값들이 0이기 때문에 불이 없음에도 불구하고, 상근이는 탈출하지 못한다. 
				if (dist[nx][ny] > 0 && dist2[cur.first][cur.second] + 1 >= dist[nx][ny] || dist2[nx][ny] != 0) continue;
				q2.push({ nx,ny });
				dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
			}
		}
		if (flag)
			cout << "IMPOSSIBLE\n";
	}
}