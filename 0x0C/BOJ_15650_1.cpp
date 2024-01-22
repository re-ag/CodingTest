#include <bits/stdc++.h>
using namespace std;
/*
	BOJ 15650 N과 M (2)
	https://www.acmicpc.net/problem/15650
*/
int n, m;
vector<int> v;

void func(int index) {
  if (v.size() == m) {
    for (auto a : v)
      cout << a << ' ';
    cout << '\n';
    return;
  }
  for (int i = index; i < n; i++) {
      v.push_back(i + 1);
      func(i + 1);
      v.pop_back();
  }
}
int main() {
  cin >> n >> m;
  func(0);
}