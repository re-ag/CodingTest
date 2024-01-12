#include <bits/stdc++.h>
using namespace std;
/*
    BOJ 2573 빙산
    https://www.acmicpc.net/problem/2573

     year 증가시키면서 빙산 녹이기
        * 상하좌우 보면서 0의개수 count -> board[i][j][year+1] = count
        * board[n-2][m-2]까지 검색을 다 마쳤다면 -> year++;
*/
#define X first
#define Y second
int n, m, year;
// [2] : 0 or 1, 해가 지날 때마다 바뀌는 빙산 높이를 두가지로 나누어서 생각하기.
int board[301][301][2];
bool vis[301][301][2];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };


bool checkMelting(int y) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j][y] != 0)
                return false;
        }
    }
    return true;
}

void  prntBoard(int y) {
    cout << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j][y] << ' ';
        }
        cout << '\n';
    }
}

void  clearBoard(int y) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            board[i][j][y] = 0;
    }
}
int main() {
    queue<pair<int, int>> q;
    cin >> n >> m;
    int y = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j][y];
        }
    }

    while (true) {
        int reg = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (!vis[i][j][y] && board[i][j][y] != 0) {
                    q.push({ i,j });
                    vis[i][j][y] = true;
                    ++reg;
                    while (!q.empty()) {
                        auto cur = q.front(); q.pop();
                        int zCnt = 0;
                        for (int dir = 0; dir < 4; dir++) {
                            int nx = dx[dir] + cur.X;
                            int ny = dy[dir] + cur.Y;
                            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                            if (board[nx][ny][y] == 0) ++zCnt;
                            if (vis[nx][ny][y] || board[nx][ny][y] == 0) continue;
                            q.push({ nx,ny });
                            vis[nx][ny][y] = true;
                        }
                        // Change y ( y XOR 1 )
                        board[cur.X][cur.Y][y xor 1] = (board[cur.X][cur.Y][y] - zCnt < 0 ? 0 : board[cur.X][cur.Y][y] - zCnt);
                    }
                }
            }
        }
        if (checkMelting(y xor 1) && (reg <= 1)) {
            ans = 0; 
            break;
        }
        else {
            if (reg > 1) { // 분리가 되었다면
                break;
            }
            else {
                ans++;
                clearBoard(y); // 방금 다 쓴 BOARD값 초기화
                y = y xor 1;
                //prntBoard(y); // BOARD로 구한 다음 년도의 BOARD값 확인
                for (int k = 0; k < n; k++) { // VIS 배열 초기화
                    for (int l = 0; l < m; l++)
                        vis[k][l][0] = vis[k][l][1] = false;
                }
            }
        }
        
    }
    cout << ans;

}