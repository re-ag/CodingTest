#include <iostream>
#include <queue>
#include <tuple>
#include <iomanip>
#include <algorithm>
using namespace std;
/*
	BOJ 7569 토마토
	https://www.acmicpc.net/problem/7569

	board의 값이 0인 모든 안익은 토마토가 익었다는 시점을 언제 알 수 있을까?

	그게 문제가 아니었다.
	익은 토마토는 동시에 익는다!

	문제는 익은 토마토의 위치값을 입력받는 동시에 큐에 넣어주는 것이 포인트다.
	만약 그렇게 하지 않고 for문을 순회하면서 방문하지 않은 익은 토마토에 대해 bfs 를 순회하면 안된다. => 최소 날짜를 알 수 없음
*/

int h, n, m;
int board[101][101][101];
bool dist[101][101][101];

int dh[6] = { 1, -1, 0, 0, 0, 0 };
int dx[6] = { 0, 0, 1, -1, 0, 0 };
int dy[6] = { 0, 0, 0, 0, -1, 1 };
int main() {
	queue<tuple<int, int, int>> q;
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			fill(dist[i][j], dist[i][j] + 101, false);
			for (int k = 0; k < m; k++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1)
					q.push(make_tuple(i, j, k));
			}
		}
	}
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		tie(curH, curX, curY) = cur;
		for (int dir = 0; dir < 6; dir++) {
			int nh = get<0>(cur) + dh[dir];
			int nx = get<1>(cur) + dx[dir];
			int ny = get<2>(cur) + dy[dir];
			if (nh < 0 || nx < 0 || ny < 0 || nh >= h || nx >= n || ny >= m) continue;
			if (board[nh][nx][ny] != 0 || dist[nh][nx][ny]) continue;
			q.push(make_tuple(nh, nx, ny));
			board[nh][nx][ny] = board[curH][curX][curY] + 1;
			dist[nh][nx][ny] = true;
		}
	}

	int max_ = -1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (board[i][j][k] == 0) {
					cout << "-1\n";
					return 0;
				}
				else if (board[i][j][k] > 0) {
					max_ = max(max_, board[i][j][k]);
				}
			}
		}
	}
	cout << max_ - 1;
}