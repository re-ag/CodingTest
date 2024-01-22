#include <bits/stdc++.h>
using namespace std;
/*
	BOJ 15650 N과 M (2)
	https://www.acmicpc.net/problem/15650
*/


int n, m;
int tmp[8];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = m; i < n; i++)
		tmp[i] = 1;
	do {
		for (int i = 0; i < n; i++) {
			if (tmp[i] == 0)
				cout << i + 1 << ' ';
		}
		cout << '\n';
	} while (next_permutation(tmp, tmp + n));
}