#include <bits/stdc++.h>
using namespace std;
/*
	BOJ 15649 N과 M (1)
	https://www.acmicpc.net/problem/15649
*/
int n, m;
vector<int> v;
bool isused[9];
void func(int index) {
  if (v.size() == m) {
    for (auto a : v)
      cout << a << ' ';
    cout << '\n';
    return;
  }
  for (int i = 0; i < n; i++) {
    if (!isused[i]) {
      isused[i] = true;
      v.push_back(i + 1);
      func(i + 1);
      isused[i] = false;
      v.pop_back();
    }
  }
}
int main() {
  cin >> n >> m;
  func(0);
}