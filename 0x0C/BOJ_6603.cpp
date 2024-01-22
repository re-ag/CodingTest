#include <bits/stdc++.h>
using namespace std;
/*
  BOJ 6603 로또
  https://www.acmicpc.net/problem/6603
*/
int k;
int num[14];
int ans[7];
void func(int n, int idx) {
  if (n == 6) {
    for (int i = 0; i < 6; i++)
      cout << num[ans[i]] << ' ';
    cout << '\n';
    return;
  }
  for (int i = idx; i < k; i++) {
    ans[n] = i;
    func(n+1, i+1);
  }
}
int main() {
  while (true) {
    cin >> k;
    if (k == 0)
      break;
    for (int i = 0; i < k; i++)
      cin >> num[i];
    func(0, 0);
    cout << '\n';
  }
}