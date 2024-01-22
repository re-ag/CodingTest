#include <bits/stdc++.h>
using namespace std;
/*
	BOJ 1992 쿼드트리
	https://www.acmicpc.net/problem/1992

	1. 함수의 정의
	void func(int x, int y, int n) 
		x,y 를 시작점으로 하는 n x n 배열의 압축결과를 ans에 추가함
	2. Base condition
		배열의 모든 원소가 같은 경우 원소값  string에 추가
	3. 재귀식
	모든 원소가 같다면 ans += arr[x][y];
	모든 원소가 같지 않다면
	ans += "(";
	func(x, y, n/2);
	func(x, y+n/2 , n/2);
	func(x + n/2, y, n/2);
	func(x + n/2, y + n/2, n/2);
	ans+=")";
*/

int N;
string ans;
string arr[64];

bool check(int x, int y, int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (arr[x][y] != arr[i][j])
				return false;
		}
	}
	return true;
}
void func(int x, int y, int n) {
	if (check(x, y, n)) {
		ans += arr[x][y];
		return;
	}
	ans += "(";
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			func(x + i * n / 2, y + j * n / 2, n / 2);
		}
	}
	ans += ")";
	return;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	func(0, 0, N);
	cout << ans;
}