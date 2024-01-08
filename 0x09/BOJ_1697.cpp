#include <bits/stdc++.h>
using namespace std;

/*
    BOJ 1697 숨바꼭질
    https://www.acmicpc.net/problem/1697

    5 17 -> 4
    5 -> -1, +1, *2
     5-10-9-18-17
     5-4-8-16-17
*/
bool vis[100001];
int n, k;
int dx[3] = { -1, 1, 2 };
int main() {
    cin >> n >> k;
    int ans = 0;
    queue<pair<int, int>> q;
    q.push({ n, ans });
    vis[n] = true;
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int cur = p.first;
        int n = p.second;
      /*  if (cur == k) {
            cout << n;
            return 0;
        }*/
        for (int i = 0; i < 3; i++) {
            if (i != 2) {
                if (cur + dx[i] < 0 || cur + dx[i] > 100000) continue;
                if (vis[cur + dx[i]]) continue;
                q.push({ cur + dx[i], n + 1 });
                vis[cur + dx[i]] = true;
                if (cur + dx[i] == k) {
                    ans = n + 1;
                    break;
                }
            }
            else {
                if (cur * dx[i] < 0 || cur * dx[i] > 100000) continue;
                if (vis[cur * dx[i]]) continue;
                q.push({ cur * dx[i], n + 1 });
                vis[cur * dx[i]] = true;
                if (cur * dx[i] == k) {
                    ans = n + 1;
                    break;
                }
            }
        }
    }
    cout << ans;
}