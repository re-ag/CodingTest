#include <bits/stdc++.h>
using namespace std;
/*
    BOJ 7562 나이트의 이동
    https://www.acmicpc.net/problem/7562
*/
#define X first
#define Y second
int dx[8] = { -1, -2, -2, -1,  1,  2,  1,  2 };
int dy[8] = { -2, -1,  1,  2, -2, -1,  2,  1 };
int test, n;
int board[301][301];
int dist[301][301]; // 방문 처리를 위한 배열이면서 이동한 칸수를 저장함
int main() {
    cin >> test;
    queue<pair<int, int>> q;
    while (test--) {
        int cnt = 0;
        cin >> n;
        while (!q.empty()) q.pop(); // test case마다 queue가 항상 비어있지 않을 수 있으므로 clear 해주기
        for (int i = 0; i < n; i++) {
            fill(board[i], board[i] + n, 0); // default 0
            fill(dist[i], dist[i] + n, -1); // default -1
        }
        pair<int, int> start, end;
        cin >> start.X >> start.Y;
        cin >> end.X >> end.Y;
        if (start == end) { // 애초에 시작과 종료점이 같으면 BFS 작업 필요 X
            cout << cnt << '\n';
            continue;
        }
        q.push(start);
        dist[start.X][start.Y] = 0;

        while (dist[end.X][end.Y] == -1) {
            auto cur = q.front(); q.pop();
            for (int dir = 0; dir < 8; ++dir) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (dist[nx][ny] >= 0) continue;
                q.push({ nx, ny });
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            }
        }
        cout << dist[end.X][end.Y] << '\n';
    }
}