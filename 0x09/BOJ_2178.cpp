#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int board[102][102];
int n, m;
bool vis[102][102];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main() {
    queue<pair<int, int>> q;
    int dis = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string num;
        cin >> num;
        for (int j = 0; j < m; j++) {
            board[i][j] = num[j] - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1 && !vis[i][j]) {
                vis[i][j] = 1;
                q.push({ i,j });
                dis = board[i][j];
                while (!q.empty()) {
                    auto p = q.front(); q.pop();
                    for (int d = 0; d < 4; d++) {
                        int nx = p.X + dx[d];
                        int ny = p.Y + dy[d];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if (board[nx][ny] == 0 || vis[nx][ny]) continue;
                        vis[nx][ny] = true;
                        board[nx][ny] = board[p.X][p.Y] + 1; // 경로 증가 부분!
                        q.push({ nx,ny });
                    }
                }
            }
        }
    }

    cout << board[n - 1][m - 1];
    return 0;
}