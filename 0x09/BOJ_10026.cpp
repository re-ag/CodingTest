#include <bits/stdc++.h>
using namespace std;
/*
    BOJ 10026 적록색약
    https://www.acmicpc.net/problem/10026
*/
#define X first
#define Y second

string board[101];
bool dist[101][101];
int n;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({ i,j });
    dist[i][j] = true;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (dist[nx][ny] || board[nx][ny] != board[i][j]) continue;
            q.push({ nx,ny });
            dist[nx][ny] = true;
        }
    }
}
int area() {
    int cnt = 0;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!dist[i][j]) {
                ++cnt;
                bfs(i, j);
            }
        }
    }
    return cnt;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    cout << area() << ' ';

    for (int i = 0; i < n; i++)
        fill(dist[i], dist[i] + n, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'R')
                board[i][j] = 'G';
        }
    }
    cout << area();
}