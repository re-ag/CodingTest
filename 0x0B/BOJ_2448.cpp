#include <bits/stdc++.h>
using namespace std;
/*
	BOJ 2448 별 찍기 - 11
	https://www.acmicpc.net/problem/2448
	
	1. 함수의 정의
		void func(int x, int y, int n); // x, y 를 시작점으로 n x (2n-1) 배열에 별 트리 찍는 함수
	2. Base condition
		n == 3일 때 가장 작은 별 트리 찍으면 됨
	3. 재귀식
		1. func(x, y + n/2, n/2)
		2. func(x + n/2, y, n/2)
		3. func(x + n/2, y + n, n/2)

*/
string arr[3100];// 별을 담을 배열
int N;

void func(int x, int y, int n) {
	if (n == 3) {
		arr[x][y+2] = '*';
		arr[x + 1][y + 1] = '*';
		arr[x + 1][y + 3] = '*';
		for (int i = 0; i < 5; i++)
			arr[x + 2][y + i] = '*';
		return;
	}
	func(x, y + n / 2, n / 2);
	func(x + n / 2, y, n / 2);
	func(x + n / 2, y + n, n / 2);

}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		arr[i] = "";
		for (int j = 0; j < (2 * N - 1); j++)
			arr[i] += ' ';
	}
	func(0, 0, N);
	for (int i = 0; i < N; i++)
		cout << arr[i] << '\n';
 }