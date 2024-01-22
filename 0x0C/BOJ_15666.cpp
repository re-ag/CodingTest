#include <algorithm>
#include <iostream>
using namespace std;
/*
  BOJ 15666 N과 M(12)
  https://www.acmicpc.net/problem/15666
*/

int n, m;
int num[9];
int ans[9];
void func(int k, int idx){
  if(k == m){
    for(int i = 0; i< m; i++)
      cout << num[ans[i]] << ' ';
    cout << '\n';
    return;
  }
  int tmp = 0;
  for(int i = idx; i< n; i++){
    if(tmp != num[i]){
      ans[k] = i;
      tmp = num[i];
      func(k+1, i);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> num[i];
  sort(num, num + n);
  func(0,0);
}