#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
/*
	BOJ 12100 2048(Easy)
	https://www.acmicpc.net/problem/12100
*/
int n;
int arr[101][101];
int brr[101][101];
int dir[5];

void leftShift(int x, int idx) {
	for (int i = idx; i < n-1; i++) {
		arr[x][i] = arr[x][i + 1];
	}
	arr[x][n - 1] = 0;
}
void leftLine(int x) {
	for (int i = 0; i < n; i++) { // 0무시하고 일단 땡겨
		if (!arr[x][i]) leftShift(x, i);
	}
	for (int i = 0; i < n - 1; i++) {
		if (arr[x][i] == arr[x][i + 1]) {
			arr[x][i] *= 2;
			arr[x][i + 1] = 0;
		}
	}
	for (int i = 0; i < n; i++) { // 0무시하고 일단 땡겨
		if (!arr[x][i]) leftShift(x, i);
	}
}

void left() {
	for (int i = 0; i < n; i++) {
		leftLine(i);
	}
}
void rightShift(int x, int idx) {
	for (int i = idx; i > 0; i--) {
		arr[x][i] = arr[x][i - 1];
	}
	arr[x][0] = 0;
}
void rightLine(int x) {
	for (int i = n-1; i >= 0; i--) { // 0무시하고 일단 땡겨
		if (!arr[x][i]) rightShift(x, i);
	}
	for (int i = n - 1; i > 0; i--) {
		if (arr[x][i] == arr[x][i - 1]) {
			arr[x][i] *= 2;
			arr[x][i - 1] = 0;
		}
	}
	for (int i = n - 1; i >= 0; i--) { // 0무시하고 일단 땡겨
		if (!arr[x][i]) rightShift(x, i);
	}
}
void right() {
	for (int i = 0; i < n; i++) {
		rightLine(i);
	}
}
void upShift(int y, int idx) {
	for (int i = idx; i < n - 1; i++) {
		arr[i][y] = arr[i + 1][y];
	}
	arr[n - 1][y] = 0;
}

void upLine(int y) {
	for (int i = 0; i < n - 1; i++) {
		if (!arr[i][y]) upShift(y, i);
	}

	for (int i = 0; i < n - 1; i++) {
		if (arr[i][y] == arr[i + 1][y]) {
			arr[i][y] *= 2;
			arr[i + 1][y] = 0;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		if (!arr[i][y]) upShift(y, i);
	}
}

void up() {
	for (int i = 0; i < n; i++) {
		upLine(i);
	}
}
void downShift(int y, int idx) {
	for (int i = idx; i > 0; i--) {
		arr[i][y] = arr[i - 1][y];
	}
	arr[0][y] = 0;
}

void downLine(int y) {
	for (int i = n - 1; i > 0; i--) {
		if (!arr[i][y]) downShift(y, i);
	}

	for (int i = n - 1; i > 0; i--) {
		if (arr[i][y] == arr[i - 1][y]) {
			arr[i][y] *= 2;
			arr[i - 1][y] = 0;
		}
	}
	for (int i = n - 1; i > 0; i--) {
		if (!arr[i][y]) downShift(y, i);
	}
}
void down() {
	for (int i = 0; i < n; i++) {
		downLine(i);
	}
}
void print() {
	cout << "=====================\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(2) <<  arr[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "=====================\n";
}

void reset() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = brr[i][j];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int max_ = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> brr[i][j];
	reset();
	//left(); up(); left(); // 23200
	//print();
	//return 0l;
	for (int i = 0; i <= ((1 << 10) -1); i++) {
		int num = i;
		for (int k = 0; k < 5; k++) {
			dir[k] = num % 4;
			num /= 4;
		}

		for (int k = 0; k < 5; k++) {
			switch (dir[k]) {
			case 0:
				up();
				break;
			case 1:
				down();
				break;
			case 2:
				left();
				break;
			case 3:
				right();
				break;
			}
			for (int ii = 0; ii < n; ii++) {
				for (int j = 0; j < n; j++) {
					max_ = max(max_, arr[ii][j]);
				}
			}
		}

		// reset arr
		reset();

	}
	cout << max_;
}