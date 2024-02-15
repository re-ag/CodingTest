#include <iostream>
#include <string>
using namespace std;
/*
	BOJ 14891 골드5 "톱니바퀴"
	https://www.acmicpc.net/problem/14891
*/
int k;
string arr[4];
int r[4];
bool change[4];
int result() {
	int res = 0;
	if (arr[0][0]) res += 1;
	if (arr[1][0]) res += 2;
	if (arr[2][0]) res += 4;
	if (arr[3][0]) res += 8;
	return res;
}

void check() {
	if (arr[0][2] != arr[1][6]) { //0과 1비교
		change[0] = change[1] = true;
	}
	if (arr[1][2] != arr[2][6]) { // 1과 2비교
		change[1] = change[2] = true;
	}
	if (arr[2][2] != arr[3][6]) { // 2와 3 비교
		change[2] = change[3] = true;
	}
}
void setRot(int idx, ) {

}
void rotate(int idx, int dir) {
	char temp[8];
	if (dir == 1) { // 시계방향
		for (int i = 1; i < 8; i++) {
			temp[i] = arr[idx][i - 1];
		}
		temp[0] = arr[idx][7];
		for (int i = 0; i < 8; i++)
			arr[idx][i] = temp[i];
	}
	else { // 반시계방향
		
		for (int i = 0; i < 7; i++) {
			temp[i] = arr[idx][i + 1];
		}
		temp[7] = arr[idx][0];
		for (int i = 0; i < 8; i++)
			arr[idx][i] = temp[i];
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < 4; i++) cin >> arr[i];
	cin >> k;
	while (k--) {
		int i, d;
		cin >> i >> d;
		r[i] = d;
		check();
		rotate(i, d);
	}

	cout << result();
	return 0;
}