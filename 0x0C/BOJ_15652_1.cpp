#include <bits/stdc++.h>
using namespace std;
/*
  BOJ 15652 N과 M-(4)
  https://www.acmicpc.net/problem/15652
*/
int n, m;
int arr[9];
void func(int k) { // k개의 수열을 채운 상태임
  if (k == m) { // m개 다 채운 경우 출력
    for (int i = 0; i<m; i++)
      cout << arr[i]+1 << ' ';
    cout << '\n';
    return;
  }
  int st = 0; // 0번부터 확인
  if (k != 0) // 1개 이상 채워진 경우, 마지막 원소값부터 확인하기(오름차순으로 채우기 위해)
    st = arr[k-1];
  for (int i = st; i < n; i++) {
    arr[k] = i; 
    func(k+1);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  func(0);
}