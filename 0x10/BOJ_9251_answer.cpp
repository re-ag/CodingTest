#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
    BOJ 9251 골드5 "LCS"
    https://www.acmicpc.net/problem/9251

    1. 테이블 정의
        dp[i][j] = str1의 0~i-1까지의 부분 문자열과 str2의 0~j-1까지의 부분 문자열 간의 LCS 
    2. 점화식 정의
        dp[i][j] 는
        if(str1[i-1] == str2[j-1]) // 현재 두 문자가 같다면 이전 문자열[i-1][j-1]의 길이에 현재 문자 길이(1)를 더하면 됨
            dp[i-1][j-1] + 1
        else                       // i가 없을 경우의 길이와 j가 없을 경우의 길이의 최대값
            max(dp[i-1][j], dp[i][j-1])
    3. 초기값
        dp의 0행, 0열은 모두 0으로 초기화
*/
string str1;
string str2;
int dp[1001][1001];
int main(){
  cin >> str1 >> str2;
  for(int i = 1; i<=str1.length(); i++){
    for(int j = 1; j<= str2.length(); j++){
      if(str1[i-1] == str2[j-1]){
        dp[i][j] = dp[i-1][j-1] + 1;
      }
      else{
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  cout << dp[str1.length()][str2.length()];
}