#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
  BOJ 15486 골드5 "퇴사 2"
  https://www.acmicpc.net/problem/15486

  1. 테이블 정의
    dp[k] = k일부터 시작했을 때 최대 수익
  2. 점화식 정의
    2-1. i일에 상담한 경우 날짜가 n일을 넘지 않는다면?
        dp[i] = max( dp[i+t[i]] + p[i], dp[i+1])
        {(i+t[i])일의 수익과 현재 날짜의 수익} vs {i+1일 시작했을 때의 수익} 의 최대값
        이를 n부터 1일까지 순회하기 때문에, dp[i+1]은 항상 최대 수익을 유지하고 있음 
        따라서 현재 날짜에 상담한 경우의 수익과, 그러지 않는 경우의 최대 수익을 비교해야 함!

    2-2. n일을 넘는다면?
        현재 날짜의 상담을 못하니 최대 수익으로 갱신함

  3. 초기값
    dp[0] = 0, dp[n+1] = 0;
*/
int n;
int ans;
vector<int> t;
vector<int> p;
vector<int> dp;
int main(){
  t.push_back(0); // index 0
  p.push_back(0); // index 0
  int num1;
  int num2;
  cin >> n;
  dp.assign(n+2, 0); // is it right?
  for(int i = 0; i<n; i++){
    cin >> num1 >> num2;
    t.push_back(num1);
    p.push_back(num2);
  }
  for(int i = n; i>=1; i--){
    if(i+t[i] <= n+1){
      dp[i] = max(dp[i+t[i]] + p[i], dp[i+1]);
    }
    else{
      dp[i] = dp[i+1];
    }
  }
  cout << *max_element(dp.begin(), dp.end());
}