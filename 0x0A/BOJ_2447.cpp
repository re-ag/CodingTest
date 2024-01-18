#include <bits/stdc++.h>
using namespace std;
/*
	BOJ 2447 별찍기 - 10
	https://www.acmicpc.net/problem/2447

	1. 함수 정의
		void func(int x, int y, int n) // [x][y] 를 시작점으로 nxn 배열을 규칙대로 별을 찍음
	2. Base condition
        n = 3 인 경우, 
        [x][y] ~ [x+n-1][y+n-1] 까지 
        ***
        * *
        *** 저장
	
	3. 재귀식
        sub = n/3
        1,2,3,4,5,6,7,8,9 구역으로 나눠
        5구역은 sub x sub 만큼 ' '저장
        1,2,3,4,6,7,8,9 구역은 sub x sub 만큼 별 모양 출력

*/
int N;
char arr[2300][2300];

void fill(int x, int y, int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			arr[i][j] = ' ';
		}
	}
}

void func(int x, int y, int n) {
	if (n == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == 1 && j == 1)
					arr[x+i][y+j] = ' ';
				else
					arr[x+i][y+j] = '*';
			}
		}
		return;
	}
	int sub = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) {
				fill(x + i * sub, y + j * sub, sub);
			}
			else {
				func(x + i * sub, y + j * sub, sub);
			}
		}
	}
}
int main() {
	cin >> N;
	func(0, 0, N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
}