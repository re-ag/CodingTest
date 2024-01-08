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
int main() {
    cin >> n >> k;
    int ans = 0;
    queue<pair<int, int>> q;
    q.push({ n, ans });
    vis[n] = true;
    while (!vis[k]) {
        auto p = q.front(); q.pop();
        int cur = p.first;
        int n = p.second;
        for (int nxt : { cur - 1, cur + 1, cur * 2}) {
            if (nxt < 0 || nxt > 100000) continue;
            if (vis[nxt]) continue;
            q.push({ nxt, n + 1 });
            vis[nxt] = true;
            if (nxt == k) ans = n + 1;
        }
    }
    cout << ans;
}