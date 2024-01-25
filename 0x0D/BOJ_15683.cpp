#include <cmath>
#include <iostream>
using namespace std;
/*
  BOJ 15684 감시
  https://www.acmicpc.net/problem/15683
*/
int n, m;
int arr[9][9];
int tmp[9][9];
int ans = 81;
int camX[9], camY[9];
int degcase[9];

int countZero() {
    int num = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!arr[i][j])
                num++;
    return num;
}
void reset() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 9)
                arr[i][j] = 0;
        }
    }
}
void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }
}
void right(int x, int y) {
    for (int i = y + 1; i < m; i++) {
        if (arr[x][i] == 6)
            break;
        if (!arr[x][i])
            arr[x][i] = 9;
    }
}
void left(int x, int y) {
    for (int i = 0; i < y; i++) {
        if (arr[x][i] == 6)
            break;
        if (!arr[x][i])
            arr[x][i] = 9;
    }
}
void top(int x, int y) {
    for (int i = 0; i < x; i++) {
        if (arr[i][y] == 6)
            break;
        if (!arr[i][y])
            arr[i][y] = 9;
    }
}
void bottom(int x, int y) {
    for (int i = x + 1; i < n; i++) {
        if (arr[i][y] == 6)
            break;
        if (!arr[i][y])
            arr[i][y] = 9;
    }
}
void cctv(int cam, int deg) {
    int x = camX[cam];
    int y = camY[cam];

    if (arr[x][y] == 1) {
        if (deg == 0) // 우
            right(x, y);
        else if (deg == 1) // 하
            bottom(x, y);
        else if (deg == 2) // 좌
            left(x, y);
        else //  상
            top(x, y);
    }
    else if (arr[x][y] == 2) {
        if (deg == 0 || deg == 2) { // 좌우
            left(x, y);
            right(x, y);
        }
        else if (deg == 1 || deg == 3) { // 상하
            top(x, y);
            bottom(x, y);
        }
    }
    else if (arr[x][y] == 3) {
        switch (deg) {
        case 0:
            right(x, y);
            top(x, y);
            break;
        case 1:
            right(x, y);
            bottom(x, y);
            break;
        case 2:
            left(x, y);
            bottom(x, y);
            break;
        case 3:
            left(x, y);
            top(x, y);
            break;
        }
    }
    else if (arr[x][y] == 4) { //
        switch (deg) {
        case 0:
            top(x, y);
            right(x, y);
            left(x, y);
            break;
        case 1:
            top(x, y);
            right(x, y);
            bottom(x, y);
            break;
        case 2:
            bottom(x, y);
            right(x, y);
            left(x, y);
            break;
        case 3:
            top(x, y);
            left(x, y);
            bottom(x, y);
            break;
        }

    }
    else if (arr[x][y] == 5) { //나의 상하좌우
        top(x, y);
        right(x, y);
        left(x, y);
        bottom(x, y);
    }
}

int main() {
    int camCnt = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] >= 1 && arr[i][j] <= 5) {
                camX[camCnt] = i;
                camY[camCnt] = j;
                ++camCnt;
            }
        }
    }
    for (int t = 0; t < pow(4, camCnt); t++) {
        int tmp = t;
        for (int c = camCnt - 1; c >= 0; c--) {
            int p = (int)pow(4, c);
            degcase[c] = tmp / p;
            tmp %= p;
        }

        for (int i = 0; i < camCnt; i++) {
            cctv(i, degcase[i]);
        }
        ans = min(ans, countZero());
        reset();
    }
    cout << ans;
}