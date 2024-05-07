#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
  BOJ 13335 실버1 "트럭"
  https://www.acmicpc.net/problem/13335

  SFT 42583 Lv2 "다리를 지나는 트럭"
  https://school.programmers.co.kr/learn/courses/30/lessons/42583
*/
int n, w, L;
vector<int> trucks;
queue<int> bridge;
int sum = 0;
int cnt = 0;
int tmp;
int main() {
  cin >> n >> w >> L;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    trucks.push_back(tmp);
  }
  int idx = 0;
  int cur;
  while (true) {
    if (idx > n - 1) {
      cnt += w;
      break;
    }
    cur = trucks[idx];
    cnt++;
    // cout << cur << " , " << cnt << '\n';
    if (bridge.size() == w) {
      sum -= bridge.front();
      bridge.pop();
    }
    if (sum + cur <= L) {
      bridge.push(cur);
      sum += cur;
      ++idx;
    } else {
      bridge.push(0);
    }
  }
  cout << cnt;
}