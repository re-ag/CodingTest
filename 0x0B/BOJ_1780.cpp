#include <bits/stdc++.h>
using namespace std;
/*
	BOJ 1780 종이의 개수
	https://www.acmicpc.net/problem/1780

	1. 정의
	void func(int sx, int sy, int n); // [sx][se] ~ [sx+n-1][se+n-1]까지의 -1, 0, 1종이의 수를 count시키는 함수
	2. base condition
	n = 1일 때는 -1, 0, 1를 count 시키기
	3. 재귀식
	[sx][sy] ~ [N-1][N-1] 까지 모든 원소가 x로 같다면 arr[x+1]++; return;
	같지 않다면 9개로 쪼갬
		1. func(sx, sy, n/3)
		2. func(sx, sy+n/3, n/3)
		3. func(sx, sy+2*n/3, n/3)
		4. func(sx + n/3, sy, n/3)
		5. func(sx + n/3, sy + n/3, n/3)
		6. func(sx + n/3, sy + 2*n/3, n/3)
		7. func(sx + 2*n/3, sy, n/3)
		8. func(sx + 2*n/3, sy + n/3, n/3)
		9. func(sx + 2*n/3, sy + 2*n/3, n/3)
*/
int N;
int ans[3]; // -1, 0, 1
int arr[2200][2200]; // 16MB...이상...

void func(int sx, int sy, int n) {
	if (n == 1) {
		ans[arr[sx][sy] + 1]++;
		return;
	}
	bool all = true;
	int first = arr[sx][sy];
	for (int i = sx; i < sx + n; i++) {
		for (int j = sy; j < sy + n; j++) {
			if (arr[i][j] != first) {
				all = false;
				break;
			}
		}
	}
	if (all) {
		ans[first + 1]++;
		return;
	}
	else {
		int sub = n / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				func(sx + i * sub, sy + j * sub, sub);
			}
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}
	func(0, 0, N);
	for (int i = 0; i < 3; i++)
		cout << ans[i] << '\n';
}