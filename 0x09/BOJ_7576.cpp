#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int board[1001][1001];
int n, m;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int dist[1001][1001];

int main() {
	queue<pair<int, int>> q;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				q.push({ i,j });
				dist[i][j] = 1;
			}
			if(board[i][j] == -1)
				dist[i][j] = -1; // 
		}
	}

	while (!q.empty()) {
		auto p = q.front(); q.pop();
		for (int dis = 0; dis < 4; dis++) {
			int nx = p.X + dx[dis];
			int ny = p.Y + dy[dis];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (board[nx][ny] == -1 || dist[nx][ny] > 0) continue;
			dist[nx][ny] = dist[p.X][p.Y] + 1;
			q.push({ nx,ny });
		}
	}
	// dist의 첫번째 값을 0으로 할 경우: dist의 -1값을 제외한 가장 최소값이 0인 경우 -> 다 익지 못함 & 다 익은 상태
	// dist의 첫번째 값을 1로 할 경우: dist의 -1을 제외한 최소값이 0인 경우(다 익지 못함), 1인 경우(이미 다 익음)
	int chk = 1000000;
	int date = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j]!= -1) {
				chk = min(chk, dist[i][j]);
				date = max(date, dist[i][j]);
			}

		}
	}
	if (chk == 0) cout << -1;
	else if (chk == -1) cout << 0;
	else cout << date - 1;
	
}