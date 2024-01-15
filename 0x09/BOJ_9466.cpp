#include <bits/stdc++.h>
using namespace std;
/*
	BOJ 9466 텀 프로젝트
	https://www.acmicpc.net/problem/9466

	arr[n] 이 나 자신일 때 까지 순회
	-> 순회하다가 나 자신을 발견하면 하나의 팀이 됨
	-> 순회하다가 자기 자신을 선택한 사람을 발견하면, 난 팀이 될 수 없음


	결국 팀이 되지 못하는 사람은 -> 순환 그래프 내 속하지 않는 노드임
	따라서 모든 arr원소에 대해서 순환 그래프에 속하는지 아닌지 검사하여 판단 가능
	But, O(N^2)
*/

int test, n;
int arr[100001];
int state[100001];

bool iscycle(int idx) {
	int cur = idx;
	for (int i = 1; i <= n; i++) {
		cur = arr[cur];
		if (cur == idx) return true;
	}
	return false;
}
int main() {
	queue<int> q;
	cin >> test;
	while (test--) {
		int cnt = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			state[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			if (!iscycle(i)) cnt++;
		}

		cout << cnt << '\n';
	}
}