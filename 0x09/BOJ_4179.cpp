#include <bits/stdc++.h>
using namespace std;
/*
    BOJ 4179 불!
    https://www.acmicpc.net/problem/4179

*/

#define X first
#define Y second
int R, C;
string board[1001];
int fire[1001][1001];
int way[1001][1001];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int main() {
    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < R; i++) {
        fill(fire[i], fire[i] + C, -1);
        fill(way[i], way[i] + C, -1);
    }   
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 'F') {
                fire[i][j] = 0;
                q1.push({ i,j });
            }
            if (board[i][j] == 'J') {
                way[i][j] = 0;
                q2.push({ i,j });
            }
        }
    }
    while (!q1.empty()) {
        auto p = q1.front(); q1.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = p.X + dx[dir];
            int ny = p.Y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if (board[nx][ny] == '#' || fire[nx][ny] >= 0) continue;
            fire[nx][ny] = fire[p.X][p.Y] + 1;
            q1.push({ nx,ny });
        }
    }
    while (!q2.empty()) {
        auto p = q2.front(); q2.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = p.X + dx[dir];
            int ny = p.Y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
                // 탈출을 성공했다는 의미와 같음!
                cout << way[p.X][p.Y] + 1;
                return 0;
            }
            // 이미 방문했거나 벽인 경우 continue
            if (way[nx][ny] > 0 || board[nx][ny] == '#') continue;
            // 다음에 도착할 장소에 이미 불이 난 경우 continue 
            if (way[p.X][p.Y] + 1 >= fire[nx][ny] && fire[nx][ny] != -1) continue;
            way[nx][ny] = way[p.X][p.Y] + 1;
            q2.push({ nx, ny });
        }
    }
    // 방문 가능한 경로를 모두 방문했지만 탈출을 못한 경우
    cout << "IMPOSSIBLE\n";
}