// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/cd14bec9ecff461ab840f853ed0eb87f
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
// ###### 굳이 board의 값을 int[][]로 할 필요가 없다는 걸 알게된 부분
string board[102]; // board[][] 의 값이 '0'또는 '1' 이기 때문에


int dist[102][102]; // int 형으로 거리값을 갱신할 배열 -> 0 이상일 경우 방문한 것으로 판단 가능 
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    // dist의 값은 초기값 -1
    for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);
    queue<pair<int, int> > Q;
    Q.push({ 0,0 }); // 시작점은 (0,0)
    dist[0][0] = 0; // 시작점의 거리값은 0으로 설정
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // 거리값이 0이상인 경우(이미 방문한 곳) 혹은 지도위치가 '0'값일 때 => pass
            if (dist[nx][ny] >= 0 || board[nx][ny] != '1') continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({ nx,ny });
        }
    }
    cout << dist[n - 1][m - 1] + 1; // 문제의 특성상 거리+1이 정답
}