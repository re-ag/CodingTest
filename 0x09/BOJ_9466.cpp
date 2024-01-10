#include <bits/stdc++.h>
using namespace std;
/*
	BOJ 9466 텀 프로젝트
	https://www.acmicpc.net/problem/9466

	stud[n] 이 나 자신일 때 까지 순회
	-> 순회하다가 나 자신을 발견하면 하나의 팀이 됨
	-> 순회하다가 자기 자신을 선택한 사람을 발견하면, 난 팀이 될 수 없음
*/

int test, n;
int stud[100001];
int team[100001];
bool vis[100001];
int main() {
	queue<int> q;
	cin >> test;
	while (test--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> stud[i];
			team[i] = 0;
		}
		// 3 1 3 7 3 4 6
		for (int i = 1; i <= n; i++) {
			if (team[i] == 0) {
				int isTeam = -1;
				q.push(i);
				vis[i] = true;
				while (!q.empty()) {
					int me = q.front();
					int nxt = stud[me]; q.pop();
					if (team[nxt] == -1) {
						break;
					}
					if (nxt == stud[nxt]) {
						team[nxt] = 1;
						if (nxt == i) isTeam = 1;
					}
					else if (nxt == i) {
						isTeam = 1;
					}
					else {
						q.push(nxt);
						vis[nxt] = true;
					}
				}
				team[i] = isTeam;

			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (team[i] == -1) cnt++;
		cout << cnt << '\n';
	}
}