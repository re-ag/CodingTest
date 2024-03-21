#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
	BOJ 2533 사회망 서비스(SNS)
	https://www.acmicpc.net/problem/2533
*/
vector<int> lst[1'000'001];
int got[1'000'001];
vector<pair<int, int>> edges1;
vector<pair<int, int>> nonearly;
int n, eCnt;
int gCnt;
void printGot(){
  for(int i = 1; i<=n; i++)
    cout << got[i] << ' ';
  cout <<'\n';
}
void makeEdges1() { // 엣지가 1인 인접 노드가 많은 애들 찾기(걔네 먼저 얼리어답터로 만드는 것이 우선적임) => O(N^2)???
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 0; j < lst[i].size(); j++) {
      int adj = lst[i][j];
      if (lst[adj].size() == 1)
        cnt++;
    }
    if (cnt > 0)
      edges1.push_back({i, cnt});
  }
  sort(edges1.begin(), edges1.end(),
       [](auto &left, auto &right) { return left.second > right.second; });
}
void checkGot(int num) {
  // num 이 얼리어답터일 때 아이디어를 받는 간선 체크   
  for (int j = 0; j < lst[num].size(); j++) {
    int adj = lst[num][j];
    if(got[adj] > 0) continue;
    bool tmp = true;
    for(int k = 0; k < lst[adj].size(); k++){
      if(got[lst[adj][k]] == 0)
        tmp = false;
    }
    if(tmp) {
      got[adj] = 1;
      gCnt--;
    }
  }
  
}

void makeNonEarly() {
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    if (got[i] == 0) {
      for (int j = 0; j < lst[i].size(); j++) {
        int adj = lst[i][j];
        if (got[adj] == 0)
          cnt++;
      }
      nonearly.push_back({i, cnt});
    }
  }
}
int main() {
  cin >> n;
  gCnt = n;
  for (int i = 0; i < n - 1; i++) {
    int from, to;
    cin >> from >> to;
    lst[from].push_back(to);
    lst[to].push_back(from);
  }
  makeEdges1();
  while (gCnt) {
    for (int i = 0; i < edges1.size(); i++) {
      int num = edges1[i].first;
      int cnt = edges1[i].second;
      if(got[num] > 0) continue;
      got[num] = 2;
      gCnt--;
      eCnt++;
      checkGot(num);
      // printGot();
    }
    makeNonEarly();
    for (int i = 0; i < nonearly.size(); i++) {
      int num = nonearly[i].first;
      int cnt = nonearly[i].second;
      if (got[num] > 0)
        continue;
      got[num] = 2;
      gCnt--;
      eCnt++;
      checkGot(num);
      // printGot();
    }
  }
  cout << eCnt;
}