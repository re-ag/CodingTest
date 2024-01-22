#include <bits/stdc++.h>
using namespace std;
/*
  BOJ 15656 N과 M(7)
  https://www.acmicpc.net/problem/15656
*/

int n, m;
int arr[8];
int ans[8];
void func(int k) {
  if (k == m) {
    for (int i = 0; i < m; i++)
      cout << arr[ans[i]] << ' ';
    cout << '\n';
    return;
  }

  for (int i = 0; i < n; i++) {
    ans[k] = i;
    func(k + 1);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  sort(arr, arr + n);
  func(0);
}