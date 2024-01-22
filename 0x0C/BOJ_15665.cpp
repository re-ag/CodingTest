#include <bits/stdc++.h>
using namespace std;
/*
  BOJ 15665 N과 M(11)
  https://www.acmicpc.net/problem/15665
*/

int n, m;
int num[8];
int ans[8];

void func(int k) {
  if(k == m){
    for(int i= 0; i<m; i++)
      cout << num[ans[i]] << ' ';
    cout << '\n';
    return;
  }
  int tmp = 0;
  for(int i = 0; i< n; i++){
    if(tmp != num[i]){
      ans[k] = i;
      tmp = num[i];
      func(k+1);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> num[i];
  sort(num, num+n);
  func(0);
}