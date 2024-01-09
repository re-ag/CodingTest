#include <bits/stdc++.h>
using namespace std;
/*
* BOJ 2206 벽 부수고 이동하기
* https://www.acmicpc.net/problem/2206
* 
* 왜 틀렸지?
* 응 이거 때문이야 
* 너 앞으로 못가잖아~
*		4 4
*		0000
*		1000
*		0001
*		0010
*/
#define X first
#define Y second

int n, m;
string board[1000];
int dist[1000][1000][2];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int main()
{
	//queue<pair<int, int>> q;
	queue<tuple<int, int, bool>> q;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < m; j++) {
			dist[i][j][0] = dist[i][j][1] = -1;
		}
	}

	q.push(make_tuple(0, 0, 0));
	dist[0][0][0] = 0;
	dist[0][0][1] = 0;
	while (!q.empty()) {
		int curX, curY, curF;
		tie(curX, curY, curF) = q.front(); q.pop();
		if (curX == n - 1 && curY == m - 1) {
			cout << dist[curX][curY][curF] + 1;
			return 0;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			int broken = curF;
			int next = dist[curX][curY][curF] + 1;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (board[nx][ny] == '1') {
				if (!broken) broken = 1;
				else continue;
			}
			if (dist[nx][ny][broken] >= 0) continue;
			q.push({ nx,ny, broken});
			//dist[nx][ny][broken] = dist[curX][curY][broken] + 1;
			dist[nx][ny][broken] = next;
		}
	}
	//for (int k = 0; k < 2; k++) {
	//	for (int i = 0; i < n; i++) {
	//		for (int j = 0; j < m; j++)
	//			cout << setw(3) << dist[i][j][k];
	//		cout << '\n';
	//	}
	//}
	cout << -1;
}
