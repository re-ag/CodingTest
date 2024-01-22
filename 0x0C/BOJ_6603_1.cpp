#include <bits/stdc++.h>
using namespace std;
/*
  BOJ 6603 로또
  https://www.acmicpc.net/problem/6603
*/
int k;
int num[14];
int mask[14];

int main() {
  while (true) {
    cin >> k;
    if (k == 0)
      break;
    for (int i = 0; i < k; i++)
      cin >> num[i];
    for (int i = 6; i < k; i++)
      mask[i] = 1; // 뽑지 않아야 할 원소 표시

    do {
      for (int i = 0; i < k; i++) {
        if (!mask[i])
          cout << num[i] << ' ';
      }
      cout << '\n';
    } while (next_permutation(mask, mask + k));
    cout << '\n';
  }
}