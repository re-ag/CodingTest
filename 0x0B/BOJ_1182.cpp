#include <bits/stdc++.h>
using namespace std;
/*
	BOJ 1182 부분수열의 합
	https://www.acmicpc.net/problem/1182

	n개의 원소에서 부분집합의 갯수는 2^n개임. => 2^n - 1 (공집합 제외)
	각각의 원소를 선택할 건지, 선택하지 않을 건지 두 가지 경우로 나뉨
    단, s가 0인 경우에는 공집합이 포함되기 때문에 cnt를 1 감소해야 함

*/

int n, s;
int arr[21];
int cnt = 0;

void func(int cur, int tot) {
	if (cur == n) {
		if (tot == s) cnt++;
		return;
	}
	func(cur + 1, tot); // cur를 선택하지 않을 경우
	func(cur + 1, tot + arr[cur]); // cur를 선택하는 경우
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	func(0, 0);
	if (s == 0) --cnt;
	cout << cnt;
}