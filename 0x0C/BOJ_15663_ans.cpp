#include <bits/stdc++.h>
using namespace std;
/*
  BOJ 15663 N과 M(9)
  https://www.acmicpc.net/problem/15663

  중복된 값의 입력에 대한 N과 M
*/

int n, m;
int arr[9];
int ans[9];
bool isused[9];

void func(int k) {
  if (k == m) {
    for (int i = 0; i < m; i++)
      cout << arr[ans[i]] << ' ';
    cout << '\n';
    return;
  }
  int tmp = 0;
  for (int i = 0; i < n; i++) {
    // isused[i] 는 현재 index값에 대한 중복 체크!
        // { 1,2,3} 중 {1,1} 이 나오지 않게!
    // tmp != arr[i] 는 중복 수열이 나오지 않게!
        // tmp는 마지막 항을 의미한다. 즉 마지막 항과 같은 값이 나올 경우 수열로 만들어선 안된다.
        // { 1,9,9} 중 {1,9} 후에 2번째 9를 방문하려고 할 때 pass해야 한다.
    if (!isused[i] && tmp != arr[i]) { 
      isused[i] = true;
      ans[k] = i;
      tmp = arr[i];
      func(k + 1);
      isused[i] = false;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  func(0);
}
