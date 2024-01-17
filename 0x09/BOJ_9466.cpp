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

	O(N) 방법
	x 학생부터 시작해서 다음 학생으로 이동하면서,
	1. 사이클에 포함된 학생 또는 포함되지 않는 학생을 "재방문"할 경우, x는 사이클에 포함되지 않은 학생!
	   지금까지 방문한 학생들은 사이클에 포함되지 않은 학생
	2. x가 아닌 다른 학생 y를 재방문한 경우, x는 사이클에 포함되지 않으며 y는 사이클에 포함된다.
	   y에서 출발하여 다시 y에 도달할 때 까지 만나는 학생들을 사이클에 포함된 학생들로.
	   x에서 출발하여 y에 도달할 때 까지 만나는 학생들을 사이클에 포함되지 않은 학생들로 만든다.
	3. x를 재방문 할 경우, x는 사이클에 포함되는 학생.
	   x에서 시작하여 다시 x에 도달할 때 까지 만나는 학생들을 사이클에 포함된 학생으로 만든다.
	
	방문 처리를 함으로써 원래는 전체 N개의 노드마다 모든 경우를 계속 최대 N번씩 방문해야 했지만, 
	한 번 확인했을때, 방문처리를 위해 한 번 더 순회하면 N*2 만큼 반복만 할 수 있다.
	따라서 O(N)
*/

int test, n;
int arr[100001];
int state[100001];

const int NOT_VISITED = 0;
const int CYCLE_IN = -1;

bool iscycle(int idx) {
	int cur = idx;
	for (int i = 1; i <= n; i++) {
		cur = arr[cur];
		if (cur == idx) return true;
	}
	return false;
}

void run(int x) {
	int cur = x;
	while (true) {
		state[cur] = x;
		cur = arr[cur];
		if (state[cur] == x) { // 재방문했을 경우!
			while (state[cur] != CYCLE_IN) { //cur(순환그래프에 속하는 학생) 부터 다 cycle_in처리!
				state[cur] = CYCLE_IN;
				cur = arr[cur];
			}
			return;
		}
		else if (state[cur] != 0) {
			return;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
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
			if (state[i] == NOT_VISITED) run(i);
		}
		for (int i = 1; i <= n; i++) {
			if (state[i] != CYCLE_IN) cnt++;
		}
		cout << cnt << '\n';
	}
}