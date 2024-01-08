#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
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
		for (int i = 0; i < 1001; i++) {
			fill(dist[i], dist[i] + 1001, 0);
			fill(dist2[i], dist2[i] + 1001, 0);
		}
		for (int i = 0; i < n; i++) {
			cin >> board[i];
			for (int j = 0; j < m; j++) {
				if (board[i][j] == '*') {
					q.push({ i,j });
					dist[i][j] = 1;
				}
				else if (board[i][j] == '@') {
					q2.push({ i,j });
					dist2[i][j] = 1;
				}
				else if (board[i][j] == '#') {
					dist[i][j] = dist2[i][j] = -1;
				}
			}
		}

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
		cout << "dist1\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << dist[i][j] << ' ';
			cout << '\n';
		}
		bool flag = true;
		while (!q2.empty()) {
			auto cur = q2.front(); q2.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
					cout << dist2[cur.first][cur.second] << '\n';
					flag = false;
					//continue;
					break;
				}
				if (((dist2[cur.first][cur.second]+1) >= dist[nx][ny]) || dist2[nx][ny] != 0) continue;
				q2.push({ nx,ny });
				dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
			}
			if (!flag)
				break;
		}
		if(flag)
			cout << "IMPOSSIBLE\n";

		cout << "dist2\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << dist2[i][j] << ' ';
			cout << '\n';
		}
	}
}