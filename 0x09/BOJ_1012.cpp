#include <bits/stdc++.h>
using namespace std;
/*
    BOJ 1012 유기농 배추
    https://www.acmicpc.net/problem/1012
*/
#define X first
#define Y second

int n, m, t, num;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int board[51][51];
bool dist[51][51];

int main() {
    int min_ = 2501;
    queue<pair<int, int>> q;
    cin >> t;
    while (t--) {
        /*
        * 문제 입력 순서가 M -> N 이라고 했는데,
        * X(0 ≤ X ≤ M-1), Y(0 ≤ Y ≤ N-1)라고 했으니까 M이 행을 나타내고, N이 열의 개수를 나타냄
        * 따라서 나의 코드에서는 n -> m 순으로 입력받으면 됨! 
        * 
        * => 문제에 있는 변수명과 내 변수명을 헷갈려하지 말도록 문제와 테스트 케이스 값들을 잘 읽자.
        */
        cin >> n >> m >> num;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            fill(board[i], board[i] + m, 0);
            fill(dist[i], dist[i] + m, 0);
        }
        while (num--) {
            int x, y;
            cin >> x >> y;
            board[x][y] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!dist[i][j] && board[i][j] == 1) {
                    q.push({ i,j });
                    dist[i][j] = true;
                    ++cnt;
                    while (!q.empty()) {
                        auto cur = q.front(); q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                            if (board[nx][ny] == 0 || dist[nx][ny]) continue;
                            q.push({ nx,ny });
                            dist[nx][ny] = true;
                        }
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
}