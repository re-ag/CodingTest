#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
  BOJ 11053 실버2 "가장 긴 증가하는 부분 수열"
  https://www.acmicpc.net/problem/11053

  1. 테이블 정의
    dp[k] = k번째까지 부분 수열 길이의 최대값
  2. 점화식 정의
    dp[k] = (dp[0~k-1] 중 arr[k]보다 작은 원소 중 최대값) + 1
  3. 초기값
    dp[0] = 1
*/
int n;
int arr[1001];
vector<int> dp;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  dp.push_back(1);
  for (int i = 1; i < n; i++) {
    int res = 0;
    for (int j = i - 1; j >= 0; j--) {
      if (arr[j] < arr[i])
        res = max(res, dp[j]);
    }
    res += 1;
    dp.push_back(res);
  }
  cout << *max_element(dp.begin(), dp.end());
}