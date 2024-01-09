#include <bits/stdc++.h>
using namespace std;
/*
* BOJ 2206 벽 부수고 이동하기
* https://www.acmicpc.net/problem/2206
*/
#define X first
#define Y second

int n, m;
string board[1000];
int dist[1000][1000];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int main()
{
	//queue<pair<int, int>> q;
	queue<tuple<int,int,bool>> q;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		fill(dist[i], dist[i] + m, -1);
	}

	q.push(make_tuple(0,0,true));
	dist[0][0] = 0;
	while (!q.empty()) {
		int curX, curY, curF;
		tie(curX, curY, curF) = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			bool flag = curF;
			if (nx == n - 1 && ny == m - 1) {
				cout << dist[curX][curY] + 2;
				return 0;
			}
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (board[nx][ny] == '1') {
				if (curF) flag = false;
				else continue;
			}
			if (dist[nx][ny] >= 0) continue;
			q.push({ nx,ny, flag });
			dist[nx][ny] = dist[curX][curY] + 1;
		}
	}

	if (dist[n - 1][m - 1] < 0)
		cout << dist[n - 1][m - 1];
	else
		cout << dist[n - 1][m - 1] + 1;
}
