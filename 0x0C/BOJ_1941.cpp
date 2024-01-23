#include <bits/stdc++.h>
using namespace std;
/*
  BOJ 1941 소문난 칠공주
  https://www.acmicpc.net/problem/1941
*/
string arr[5];
int ans;
vector<pair<int, int>> k;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool checkK(int x, int y) {
  for (auto cur : k) {
    if (cur.first == x && cur.second == y)
      return false;
  }
  return true;
}
bool check(int x, int y) {
  if (x < 0 || y < 0 || x >= 5 || y >= 5)
    return false;
  return true;
}
void func(int x, int y) {
  if (!check(x, y))
    return;
  if (k.size() == 7) {
    int cnt = 0;
    for (auto p : k) {
      if (arr[p.first][p.second] == 'S')
        cnt++;
    }
    if (cnt >= 4)
      ans++;
    return;
  }
  pair<int,int> tmp;
  tmp.first = -1;
  tmp.second = -1;
  for(int idx = 0; idx < k.size(); idx++){
    int i = k[idx].first;
    int j = k[idx].second;
    for (int dir = 0; dir < 4; dir++) {
      int nx = i + dx[dir];
      int ny = j + dy[dir];
      if (!check(nx, ny) || !checkK(nx, ny))
        continue;
      if (tmp.first == nx && tmp.second == ny) continue;
      k.push_back({ nx, ny });
      tmp.first = nx; tmp.second = ny;
      func(nx, ny);
      k.pop_back();
    }
  }
}
int main() {
  for (int i = 0; i < 5; i++)
    cin >> arr[i];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      k.push_back({ i,j });
      func(i, j);
      k.pop_back();
    }
  }

  cout << ans;

}