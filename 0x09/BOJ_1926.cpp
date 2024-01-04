#include "bits/stdc++.h"
using namespace std;

#define X first
#define Y second

int board[502][502] = { 0 };
bool vis[502][502];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main() {
	int n, m; 
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int cnt = 0;
	int mx = 0;
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 && !vis[i][j]) {
				vis[i][j] = true;
				q.push({ i,j });
				++cnt;
				int area = 0;
				while (!q.empty()) {
					pair<int, int> cur = q.front(); q.pop();
					++area;
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if (vis[nx][ny] || board[nx][ny] != 1) continue;
						vis[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
				mx = mx < area ? area : mx;
			}
		}
	}
	

	cout << cnt << '\n' << mx;
}