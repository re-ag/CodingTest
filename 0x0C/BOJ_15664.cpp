#include <bits/stdc++.h>
using namespace std;
/*
  BOJ 15664 N과 M(10)
  https://www.acmicpc.net/problem/15664
*/
int n, m;
int num[9];
int ans[9];
bool isused[9];
void func(int k, int idx) {
  if (k == m) {
    for (int i = 0; i < m; i++)
      cout << num[ans[i]] << ' ';
    cout << '\n';
    return;
  }
  int tmp = 0;
  for (int i = idx; i < n; i++) {
    if(tmp != num[i]){ // 중복 수열 체크
      ans[k] = i;
      tmp = num[i];
      func(k + 1, i + 1);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }
  sort(num, num + n);
  func(0, 0);
}