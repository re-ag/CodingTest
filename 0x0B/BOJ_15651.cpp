#include <bits/stdc++.h>
using namespace std;
/*
  BOJ 15651 N과 M-(3)
  https://www.acmicpc.net/problem/15651
*/
int n, m;
vector<int> v;
void func(int k) {
  if (v.size() == m) {
    for (auto a : v)
      cout << a << ' ';
    cout << '\n';
    return;
  }
  for (int i = 1; i <= n; i++) {
    v.push_back(i);
    func(i + 1);
    v.pop_back();
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  func(0);
}