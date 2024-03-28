#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
    BOJ 9461 실버3 "파도반 수열"
	https://www.acmicpc.net/problem/9461

	1. 테이블 정의
		dp[k] = P(K)값
	2. 점화식 정의
		dp[k] = dp[k-5] + dp[k-1]
	3. 초기값 정의
		dp[1] = 1, dp[2] = 1, dp[3] = 1, dp[4] = 2, dp[5] = 2
		
 */
int t, n;
long long dp[101];
int main() {
  cin >> t;
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 1;
  dp[4] = 2;
  dp[5] = 2;
  while (t--) {
    cin >> n;
    for(int i = 6; i<=n; i++){
      if(dp[i] != 0) continue;
      dp[i] = dp[i-5] +dp[i-1];
    }
    cout << dp[n] << '\n';
  }
}