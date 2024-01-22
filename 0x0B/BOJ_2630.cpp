#include <bits/stdc++.h>
using namespace std;
/*
	BOJ 2630 색종이 만들기
	https://www.acmicpc.net/problem/2630

	1. 함수의 정의
	void func(int sx, int sy, n) // [sx][sy] 를 시작점으로 하는 NxN 크기의 배열 중 색종이수 count 

	2. base condition
	[sx][sy] ~ [sx + n-1][sy + n-1] 까지 같은 원소의 경우 count

	3.
	[sx][sy] ~ [sx + n-1][sy + n-1] 까지 원소가 같지 않은 경우
	sub = n / 2;
	1. func(sx, sy,sub)
	2. func(sx, sy + sub, sub)
	3. func(sx + sub, sy , sub)
	4. func(sx + sub, sy + sub, sub);

*/
int N;
int ans[2];
int arr[129][129];

bool check(int x, int y, int n) {
	for(int sx = x; sx < x+ n; sx++){
		for (int sy = y; sy < y + n; sy++)
			if (arr[x][y] != arr[sx][sy])
				return false;
	}
	return true;
}
void func(int x, int y, int n) {
	if (check(x, y, n)) {
		ans[arr[x][y]]++;
		return;
	}
	int sub = n / 2;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			func(x + i * sub, y + j * sub, sub);
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	func(0, 0, N);
	cout << ans[0] << '\n' << ans[1];
}