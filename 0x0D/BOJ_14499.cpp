#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
    BOJ 14499 "주사위 굴리기"
    https://www.acmicpc.net/problem/14499

    어려웠던 점
    * 주사위를 입체적으로 떠올려야 해서 어려웠음
    * 주사위를 어떤 자료형식으로 처리해야 할까 생각을 많이함
    * 문제에서 표현한 바와 같이 그냥 4x3 배열로 처리함
    
    아쉬웠던 점
    * 문제를 제대로 읽지 않아 시간을 날림
        * "가장 처음에 주사위에는 모든 면에 0이 적혀져 있다" => 를 안읽어서 예제1부터 이해 못함
        * "0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다."
        * "이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다." => 위 문장이랑 헷갈려서 주사위 바닥면도 0으로 초기화 시켜버림;
*/
int n, m, x, y, k;
int num[7];                                            // value of ball
int ball[4][3] = {0, 2, 0, 4, 1, 3, 0, 5, 0, 0, 6, 0}; // initial ball
int board[21][21];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void printBall() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++)
      cout << ball[i][j] << ' ';
    cout << '\n';
  }
}
int rotate(int dir) {
  int tmp = 0;
  switch (dir) {
  case 1:
    tmp = ball[1][2];
    ball[1][2] = ball[1][1];
    ball[1][1] = ball[1][0];
    ball[1][0] = ball[3][1];
    ball[3][1] = tmp;
    break;
  case 2:
    tmp = ball[1][0];
    ball[1][0] = ball[1][1];
    ball[1][1] = ball[1][2];
    ball[1][2] = ball[3][1];
    ball[3][1] = tmp;
    break;
  case 3:
    tmp = ball[0][1];
    ball[0][1] = ball[1][1];
    ball[1][1] = ball[2][1];
    ball[2][1] = ball[3][1];
    ball[3][1] = tmp;
    break;
  case 4:
    tmp = ball[2][1];
    ball[2][1] = ball[1][1];
    ball[1][1] = ball[0][1];
    ball[0][1] = ball[3][1];
    ball[3][1] = tmp;
    break;
  }
  return ball[3][1];
}
int main() {
  cin >> n >> m >> x >> y >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> board[i][j];
  int d = 0;
  int pos = 0;

  for (int i = 0; i < k; i++) {
    cin >> d;
    x += dx[d - 1];
    y += dy[d - 1];
    if (x < 0 || x >= n || y < 0 || y >= m) {
      x -= dx[d - 1];
      y -= dy[d - 1];
      continue;
    }
    pos = rotate(d); // bottom number
    if (board[x][y] != 0) {
      num[pos] = board[x][y];
      board[x][y] = 0;
    } else {
      board[x][y] = num[pos];
      // num[pos] = 0;
    }
    cout << num[7 - pos] << '\n';
  }
}