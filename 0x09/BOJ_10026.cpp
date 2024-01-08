#include <bits/stdc++.h>
using namespace std;
/*
    BOJ 10026 적록색약
    https://www.acmicpc.net/problem/10026
*/
#define X first
#define Y second

string board[101];
string blind[101];
int dist[101][101];
int n;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


int bfs(string board[101], int N) {
    map<char, int> m;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        fill(dist[i], dist[i] + n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] < 0) {
                char curChar = board[i][j];
                if (m.find(curChar) == m.end())
                    m[curChar] = 1;
                else {
                    ++m[curChar];
                }
                dist[i][j] = m[curChar];
                q.push({ i,j });
                while (!q.empty()) {
                    auto cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; ++dir) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if (dist[nx][ny] > 0 || board[nx][ny] != curChar) continue;
                        q.push({ nx,ny });
                        dist[nx][ny] = m[curChar];
                    }
                }
            }
        }
    }
    int sum = 0;
    for (auto x : m)
        sum += x.second;
    return sum;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
        blind[i] = board[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (blind[i][j] == 'R')
                blind[i][j] = 'G';
        }
    }

    cout << bfs(board, n) << " " << bfs(blind, n);
}