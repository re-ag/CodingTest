#include <algorithm>
#include <iostream>
using namespace std;
/*
    BOJ 14501 실버3 "퇴사"
    https://www.acmicpc.net/problem/14501
    
    1. 테이블 정의
        dp[k] = k일까지의 최대 이익
    2. 점화식 정의

    3. 초기값 정의
        dp[0] = p[0]
*/
int n;
int t[1001];
int p[1001];
int dp[1001];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> t[i] >> p[i];
    if (t[0] <= n)
        dp[0] = p[0];
    for (int i = 1; i < n; i++) {
        int mx = 0;
        for (int j = 0; j < i; j++) {
        if (j + t[j] < i + 1) {
            mx = max(mx, dp[j]);
        }
        }
        if (i + t[i] <= n)
        dp[i] = mx + p[i];
    }
    cout << *max_element(dp, dp + n);
}