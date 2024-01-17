#include <bits/stdc++.h>
using namespace std;
/*
	BOJ 1600 말이 되고픈 원숭이
	https://www.acmicpc.net/problem/1600
	2
	10 2
	0 0 1 0 0 1 0 0 1 0
	0 0 1 1 0 0 0 0 1 0

	ans = 10(output = -1)
	==> if(k <K)의 else문을 빼버림!!

	1
	1 1
	0
	ans = 0 (output = -1)
	==> 마지막 -1리턴 부분에 w == h == 1 인 경우 추가

*/
int K, w, h;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };
int hdx[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int hdy[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
int arr[201][201];
int dist[201][201][31];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<tuple<int, int, int>> q;
	cin >> K >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j];
            fill(dist[i][j], dist[i][j] + K +1, -1);
		}
	}
	q.push({ 0,0,0 });
	dist[0][0][0] = 0;
	while (!q.empty()) {
		int x, y, k;
		tie(x, y, k) = q.front(); q.pop();
		int d = dist[x][y][k];
		// k가 K보다 작다면 말처럼 움직이기
		if(k < K){
			for (int dir = 0; dir < 8; dir++) {
				int nx = hdx[dir] + x;
				int ny = hdy[dir] + y;
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (dist[nx][ny][k + 1] >= 0) continue; // already visited
				if (arr[nx][ny] == 1) continue; // if it is obstacle
				if (nx == h - 1 && ny == w - 1) {
					cout << dist[x][y][k] + 1<< '\n';
					return 0;
				}
				q.push({ nx,ny,k + 1 });
				dist[nx][ny][k + 1] = d + 1;
			}
		}
		
		for (int dir = 0; dir < 4; dir++) {
			int nx = dx[dir] + x;
			int ny = dy[dir] + y;
			if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
			if (dist[nx][ny][k] >= 0) continue;
			if (arr[nx][ny] == 1) continue;
			if (nx == h - 1 && ny == w - 1) {
				cout << dist[x][y][k] + 1 << '\n';
				return 0;
			}
			q.push({ nx,ny, k});
			dist[nx][ny][k] = d + 1;
		}
		
	}
	
	if (w == h && h == 1)
		cout << 0 << '\n';
	else cout << -1 << '\n';
	return 0;
}