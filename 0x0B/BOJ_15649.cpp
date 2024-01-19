#include <bits/stdc++.h>
using namespace std;
/*
	BOJ 15649 N과 M (1)
	https://www.acmicpc.net/problem/15649
*/


int n, m;
int arr[8]; // 0~(m-1) 까지 m개의 수열을 저장하는 배열
bool isused[9]; // 1~n 까지 자연수의 사용 상태를 처리하는 배열

void func(int k) { // 현재 k개 까지의 수열이 만들어진 상태
	if (k == m) { // m개의 수열이 만들어졌다면 출력 
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!isused[i]) { // 자연수 i가 사용되지 않았다면
			arr[k] = i; // k번째에 i추가
			isused[i] = true; // 사용 처리
			func(k + 1); // 나머지 수열 채우기
			isused[i] = false; // 나머지 수열 채웠다면 나는 다시 사용 가능!
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0);
}